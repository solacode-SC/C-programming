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

static int	check_type(const char *str, void *arg)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_char((int)arg);
	else if (*str == 's')
		i += print_str((char *)arg);
	else if (*str == 'p')
		i += print_ptr((unsigned long)arg, 87);
	else if (*str == 'd')
		i += print_int((int)arg);
	else if (*str == 'i')
		i += print_int((int)arg);
	else if (*str == 'u')
		i += print_unsgd((unsigned int)arg);
	else if (*str == 'x')
		i += print_hex((unsigned int)arg, 87);
	else if (*str == 'X')
		i += print_hex((unsigned int)arg, 55);
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, va_arg(args, void *));
			else if (*input == '%')
				i += print_char('%');
		}
		else
			i = i + print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
