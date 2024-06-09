/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:31:52 by soel-mou          #+#    #+#             */
/*   Updated: 2024/01/08 15:31:53 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int check_type(const char *str, va_list args) {
    int i = 0;

    if (*str == 'c')
        i += print_char(va_arg(args, int)); // Characters are promoted to int
    else if (*str == 's')
        i += print_str(va_arg(args, char *));
    else if (*str == 'p')
        i += print_ptr((unsigned long)va_arg(args, void *), 87);
    else if (*str == 'd' || *str == 'i')
        i += print_int(va_arg(args, int));
    else if (*str == 'u')
        i += print_unsgd(va_arg(args, unsigned int));
    else if (*str == 'x')
        i += print_hex(va_arg(args, unsigned int), 87);
    else if (*str == 'X')
        i += print_hex(va_arg(args, unsigned int), 55);

    return i;
}

static char *ft_strchr(const char *s, int c) {
    while (*s != (char)c)
        if (!*s++)
            return 0;
    return (char *)s;
}

int ft_printf(const char *input, ...) {
    va_list args;
    unsigned int i = 0;

    va_start(args, input);
    while (*input != '\0') {
        if (*input == '%') {
            input++;
            if (ft_strchr("cspdiuxX", *input))
                i += check_type(input, args);
            else if (*input == '%')
                i += print_char('%');
        } else {
            i += print_char(*input);
        }
        input++;
    }
    va_end(args);

    return i;
}
