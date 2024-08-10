/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 03:17:55 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/10 01:44:16 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	to_skip(char c)
{
	if (c == ' ' || c == '\t' || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	check_dup(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (1);
		if ((str[i] >= '0' && str[i] <= '9') && str[i + 1] == '-'
			&& (str[i + 2] >= '0' && str[i + 2] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_no_digit(const char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (len > 0 && to_skip(str[len - 1]))
		len--;
	if (len == 0 || check_dup(str))
		return (1);
	while (i < len)
	{
		if (to_skip(str[i]))
			i++;
		else if (str[i] < '0' || str[i] > '9')
			return (1);
		else
			i++;
	}
	return (0);
}

void	print_error(t_stack **head_a, t_stack **head_b)
{
	write(2, "Error\n", 6);
	free_all(head_a);
	free_all(head_b);
}
