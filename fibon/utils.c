#include "utils.h"


/**
 * Creates a circular linked list of Fibonacci numbers in descending order.
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
    unsigned long fib_n = 1, fib_n_minus_1 = 0, fib_n_minus_2;
    for (i = 0; i <= n; i++) {
        Node *node = (Node *) malloc(sizeof(Node));
        if (node == NULL) {
            fprintf(stderr, ERR_MEMORY_ALLOCATION_FAILED);
            exit(1);
        }
        node->data = fib_n;
        if (head == NULL) {
            head = node;
            tail = head;
        } else {
            node->next = head;
            head = node;
        }
        fib_n_minus_2 = fib_n_minus_1;
        fib_n_minus_1 = fib_n;
        fib_n = fib_n_minus_2 + fib_n_minus_1;
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
void save_circular_linked_list_to_file(Node *head, char *filename, int n) {
    Node *current;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, ERR_OPENING_FILE);
        return;
    }
    /* Write short description at the top of the file */
    fprintf(fp, "Circular Linked List contents separated by spaces:\n");

    /* Write n to file */
    fprintf(fp, "n = %d\n", n);

    /* Write nodes data to file */
    current = head;
    while (1) {
        fprintf(fp, "%lu ", current->data);
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