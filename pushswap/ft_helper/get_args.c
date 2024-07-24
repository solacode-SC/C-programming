#include "../pushswap.h"




// Function to parse the string and store the numbers in the linked list
void parseAndStoreNumbers(const char* str, stack_t** head) {
    if (is_no_digit(str) == 1)
        print_error();
    else {
        char* endPtr;
        while (*str) {
            if (*str == ' ' || *str == '\t') {
                str++;
                continue;
            }
            int num = strtol(str, &endPtr, 10);
            if (str == endPtr) {
                str++;
            } else {
                appendNode(head, num);
                str = endPtr;
            }
        }
    }

    
}

