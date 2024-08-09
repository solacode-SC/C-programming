/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:17:35 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/09 00:08:12 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

long	my_strtol(const	char	*str, char	**endptr)
{
	const char	*ptr;
	long		result;
	int			sign;

	ptr = str;
	result = 0;
	sign = 1;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	if (endptr)
		*endptr = (char *)ptr;
	return (sign * result);
}

void	parseandstorenumbers(const char *str,
		t_stack **head_a, t_stack **head_b)
{
	char	*endptr;
	long	num;

	if (is_no_digit(str))
		print_error(head_a, head_b);
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		num = my_strtol(str, &endptr);
		if (str == endptr)
			str++;
		else
		{
			if (num > INT_MAX || num < INT_MIN)
			{
				print_error(head_a, head_b);
				return ;
			}
			appendnode(head_a, (int)num);
			str = endptr;
		}
	}
}
