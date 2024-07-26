#include "pushswap.h"

// int ft_atoi(char *str) {
//     int sign = 1;
//     int result = 0;

//     while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' || *str =='')
//         str++;

//     if (*str == '-' || *str == '+') {
//         if (*str == '-')
//             sign = -1;
//         str++;
//     }

//     while (*str >= '0' && *str <= '9') {
//         result = result * 10 + (*str - '0');
//         str++;
//     }

//     return result * sign;
// }

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
        if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' || str[i+ 1] == '+'))
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
        } else if (str[i] < '0' || str[i] > '9') {
            return 1;
        } else {
            i++;
        }
    }
    return 0;
}



void print_error() {
    write(2, "Error\n", 6);
    exit(1);
}