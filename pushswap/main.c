#include "pushswap.h"

int main(int argc, char **argv) {
    int i = 1;
    stack_t* head_a = NULL;
    stack_t* head_b = NULL;
    if (argc <= 1)
        return 0;
    else {
        while (i < argc) {
            parseAndStoreNumbers(argv[i], &head_a);
            i++;
        }
        if (get_listlen(head_a) <= 2)
            print_error();
    }
    printList(head_a);
    if (isSorted(head_a))
    {
        printf("The list is already sorted.\n");
        return 0;
    }
    int len = get_listlen(head_a);
    set_algo(len, &head_a, &head_b);
    // stack_t *ref = head_a;
    printList(head_a);
    // printList(head_a);
    printList(head_b);
}