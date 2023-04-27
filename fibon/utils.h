#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node *create_circular_linked_list(int n);

void print_circular_linked_list(Node *head);

void save_circular_linked_list_to_file(Node *head, char *filename);

void free_circular_linked_list(Node *head);


#endif
