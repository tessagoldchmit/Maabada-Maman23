#include "utils.h"

/**
 * Creates a circular linked list of Fibonacci numbers with a user-specified length,
 * saves the list to a file specified by the user as a command-line argument, and
 * frees the memory used by the list. The program prompts the user to enter the
 * number of Fibonacci numbers to include in the list.
 *
 * Returns:
 *     An integer representing the exit code of the program. Returns 0 on successful
 *     execution, and 1 if an error occurs.
 */

int main(int argc, char *argv[]) {
    char *filename;
    int n;
    Node *head;

    if (argc != 2) {
        fprintf(stderr, ERR_NUM_ARGS);
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];

    printf("This program creates a circular linked list of Fibonacci numbers and saves the list to a file\n\n");
    printf("Enter the number of Fibonacci numbers to include in the list: ");
    scanf("%d", &n);

    if (n < 0) {
        fprintf(stderr, ERR_NEGATIVE_N);
        return 1;
    }

    head = create_circular_linked_list(n);
    save_circular_linked_list_to_file(head, filename, n);
    free_circular_linked_list(head);
    return 0;
}