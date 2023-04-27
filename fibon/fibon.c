#include "utils.h"


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
    printf("Enter a value for n: ");
    scanf("%d", &n);

    if (n < 0) {
        fprintf(stderr, ERR_NEGATIVE_N);
        return 1;
    }

    head = create_circular_linked_list(n);
    save_circular_linked_list_to_file(head, filename);
    free_circular_linked_list(head);
    return 0;
}