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

int is_no_digit(const char *str) {
    int i = 0;
    if (str[0] == '\0')
        return 1;
    while (str[i]) {
        if (str[i] == ' ' || str[i] == '\t')
            i++;
        if ((str[i] < '0' || str[i] > '9') && (str[i] != ' ' && str[i] != '\t'))
            return 1;
        i++;
    }
    return 0;
}



void print_error() {
    write(2, "Error\n", 6);
    exit(1);
}