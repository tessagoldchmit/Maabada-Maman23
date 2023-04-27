#include "utils.h"


int main(int argc, char *argv[]) {
    char *filename;
    int n;
    Node *head;

    if (argc != 3) {
        printf("Usage: %s <filename> <n>\n", argv[0]);
        return 1;
    }
    filename = argv[1];
    n = atoi(argv[2]);
    head = create_circular_linked_list(n);
    print_circular_linked_list(head);
    save_circular_linked_list_to_file(head, filename);
    free_circular_linked_list(head);
    return 0;
}
