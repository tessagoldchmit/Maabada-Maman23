#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

/**
@struct Note
A structure representing a None in a circular linked list
*/
typedef struct Node {
    unsigned long data; /* The integer data value of the node */
    struct Node *next; /* A pointer to the next node in the linked list */
} Node;

/* function declarations */

Node *create_circular_linked_list(int n);

void save_circular_linked_list_to_file(Node *head, char *filename, int n);

void free_circular_linked_list(Node *head);


/* Error messages */

#define ERR_MEMORY_ALLOCATION_FAILED "Error: Memory allocation failed.\n"

#define ERR_OPENING_FILE "Error: Opening file failed.\n"

#define ERR_NUM_ARGS "Error: Invalid number of arguments\n"

#define ERR_NEGATIVE_N "Error: n must be non-negative.\n"


#endif
