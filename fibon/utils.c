#include "utils.h"

int fib(int n) {
    if (n == 0 || n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

Node *create_circular_linked_list(int n) {
    Node *head = NULL;
    Node *tail = NULL;
    int i;
    for (i = n; i >= 0; i--) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = fib(i);
        if (head == NULL) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    tail->next = head;
    return head;
}

void print_circular_linked_list(Node *head) {
    Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void save_circular_linked_list_to_file(Node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    Node *current = head;
    do {
        fprintf(fp, "%d ", current->data);
        current = current->next;
    } while (current != head);
    fclose(fp);
}

void free_circular_linked_list(Node *head) {
    Node *current = head;
    do {
        Node *temp = current;
        current = current->next;
        free(temp);
    } while (current != head);
}