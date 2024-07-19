#include "pushswap.h"

int main(int argc, char **argv) {
    int i = 1;
    Node* head = NULL;
    if (argc <= 1)
        return 0;
    else {
        while (i < argc) {
            parseAndStoreNumbers(argv[i], &head);
            i++;
        }
    }
    printList(head);
}