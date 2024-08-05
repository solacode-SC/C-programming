#include "pushswap.h"

int main(int argc, char **argv) {
    int i = 1;
    stack_t* head_a = NULL;
    stack_t* head_b = NULL;
    if (argc <= 1)
        return 0;
    else {
        while (i < argc) {
            parseAndStoreNumbers(argv[i], &head_a, &head_b);
            i++;
        }
        if (get_listlen(head_a) < 2)
            print_error(&head_a, &head_b);
    }
    printList(head_a);
    // printf("\nhello");
    int len = get_listlen(head_a);
    set_algo(len, &head_a, &head_b);
    printList(head_a);
    printList(head_b);
    free_all(&head_a);
    free_all(&head_b);
}