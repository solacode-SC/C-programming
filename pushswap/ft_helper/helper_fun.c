#include "pushswap.h"


static int ft_strlen(const char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int to_skip(char c) {
    if (c == ' ' || c == '\t' || c == '-' || c == '+')
        return 1;
    else
        return 0;
}
int check_dup(const char *str) {
    int i = 0;
    while (str[i]) {
        if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' || str[i+ 1] > '9'))
            return 1;
        else if ((str[i] == '-' || str[i] == '+') && !to_skip(str[i - 1]))
            return 1;
        i++;
    }
    return 0;
}
int is_no_digit(const char *str) {
    int i = 0;
    int len = ft_strlen(str);

    while (len > 0 && to_skip(str[len - 1])) {
        len--;
    }

    if (len == 0 || check_dup(str))
        return 1;

    while (i < len) {
        if (to_skip(str[i])) {
            i++;
        }
        else if (str[i] < '0' || str[i] > '9') {
            return 1;
        }
        else {
            i++;
        }
    }
    return 0;
}



void print_error(stack_t** head_a, stack_t** head_b) {
    write(2, "Error\n", 6);
    free_all(head_a);
    free_all(head_b);
    exit(EXIT_FAILURE);
}