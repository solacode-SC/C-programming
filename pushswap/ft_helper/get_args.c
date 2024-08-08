#include "../pushswap.h"

long    my_strtol(const char* str, char **endPtr) {
    const   char    *ptr;
    long            result;
    int				sign;

    ptr = str;
    result = 0;
    sign = 1;
    while (*ptr == ' ' || *ptr == '\t')
		ptr++;

    if (*ptr == '-' || *ptr == '+') {
        if (*ptr == '-') sign = -1;
        ptr++;
    }

    while (*ptr >= '0' && *ptr <= '9') {
        int digit = *ptr - '0';
        result = result * 10 + digit;
        ptr++;
    }

    if (endPtr) *endPtr = (char *)ptr;
    return sign * result;
}


void parseAndStoreNumbers(const char* str, stack_t** head_a, stack_t** head_b) {
    if (is_no_digit(str)) {
        print_error(head_a, head_b);
    } else {
        char* endPtr;
        while (*str) {
            if (*str == ' ' || *str == '\t') {
                str++;
                continue;
            }
            long num = my_strtol(str, &endPtr);
            if (str == endPtr) {
                str++;
            } else {
                if (num > INT_MAX || num < INT_MIN) {
                    print_error(head_a, head_b);
                    return;
                }
                appendNode(head_a, (int)num);
                str = endPtr;
            }
        }
    }
}