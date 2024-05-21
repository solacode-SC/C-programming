/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsgd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:25 by soel-mou          #+#    #+#             */
/*   Updated: 2024/01/18 02:49:34 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	printall(unsigned int nb)
{
	if (nb > 9)
		print_unsgd(nb / 10);
	if (nb <= 9)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putchar((nb % 10) + 48);
}

int	print_unsgd(unsigned int nb)
{
	unsigned int	i;

	printall(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
