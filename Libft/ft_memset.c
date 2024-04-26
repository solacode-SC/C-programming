/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:34:43 by soel-mou          #+#    #+#             */
/*   Updated: 2023/11/28 09:57:02 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	uc;

	p = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len > 0)
	{
		*p = uc;
		p++;
		len--;
	}
	return (b);
}
