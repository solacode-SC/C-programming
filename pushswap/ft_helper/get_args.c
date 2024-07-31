#include "../pushswap.h"





long my_strtol(const char* str, char **endPtr) {
    long result = 0;
    int sign = 1;

    while (isspace(*str)) str++;

    if (*str == '-' || *str == '+') {
        if (*str == '-') sign = -1;
        str++;
    }

    if (!isdigit(*str)) {
        *endPtr = (char*)str;
        return 0;
    }

    while (isdigit(*str)) {
        result = result * 10 + (*str - '0');
        str++;
    }

    *endPtr = (char*)str;
    return sign * result;
}

// void parseAndStoreNumbers(const char* str, stack_t** head_a, stack_t** head_b) {
//     if (is_no_digit(str)) {
//         print_error(head_a, head_b);
//     } else {
//         char* endPtr;
//         while (*str) {
//             if (*str == ' ' || *str == '\t') {
//                 str++;
//                 continue;
//             }
//             int num = my_strtol(str, &endPtr);
//             if (str == endPtr) {
//                 str++;
//             } else {
//                 appendNode(head_a, num);
//                 str = endPtr;
//             }
//         }
//     }
// }

void parseAndStoreNumbers(const char* str, stack_t** head_a, stack_t** head_b) {
    if (is_no_digit(str)) {
        print_error(head_a, head_b);
    } else {
        char* endPtr;
        while (*str) {
            // Skip whitespace
            if (*str == ' ' || *str == '\t') {
                str++;
                continue;
            }
            // Parse the number
            long num = my_strtol(str, &endPtr);
            if (str == endPtr) {
                str++;
            } else {
                // Handle out of range values (optional)
                if (num > INT_MAX || num < INT_MIN) {
                    print_error(head_a, head_b);
                    return;
                }

                // Append the number to the stack
                appendNode(head_a, (int)num);
                str = endPtr;
            }
        }
    }
}