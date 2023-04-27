#include "utils.h"


/**
 * Calculates the nth Fibonacci number.
 *
 * Args:
 *     n: An integer specifying the index of the Fibonacci number to calculate.
 *
 * Returns:
 *     An integer representing the nth Fibonacci number.
 */
int fib(int n) {
    return (n == 0 || n == 1) ? 1 : fib(n - 1) + fib(n - 2);
}


/**
 * Creates a circular linked list of Fibonacci numbers.
 *
 * Args:
 *     n: An integer specifying the number of Fibonacci numbers to include in the list.
 *
 * Returns:
 *     A pointer to the head node of the circular linked list.
 */
Node *create_circular_linked_list(int n) {
    Node *head = NULL;
    Node *tail = NULL;
    int i;
    for (i = n; i >= 0; i--) {
        Node *node = (Node *) malloc(sizeof(Node));
        if (node == NULL) {
            fprintf(stderr, ERR_MEMORY_ALLOCATION_FAILED);
            exit(1);
        }
        node->data = fib(i);
        if (head == NULL)
            head = node;
        else
            tail->next = node;
        tail = node;
    }
    tail->next = head;
    return head;
}


/**
 * Saves the values of a circular linked list of Fibonacci numbers to a file.
 *
 * Args:
 *     head: A pointer to the head node of the circular linked list to save.
 *     filename: A string specifying the name of the file to save the list to.
 *
 * Returns:
 *     None
 */
void save_circular_linked_list_to_file(Node *head, char *filename) {
    Node *current;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, ERR_OPENING_FILE);
        return;
    }
    current = head;
    while (1) {
        fprintf(fp, "%d ", current->data);
        current = current->next;
        if (current == head)
            break;
    }
    fclose(fp);
}


/**
 * Frees the memory allocated to a circular linked list of Fibonacci numbers.
 *
 * Args:
 *     head: A pointer to the head node of the circular linked list to free.
 *
 * Returns:
 *     None
 */
void free_circular_linked_list(Node *head) {
    Node *current = head;
    Node *temp;
    while (current != NULL && current->next != head) {
        temp = current;
        current = current->next;
        free(temp);
    }
    if (current == head)
        free(current);
}