/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:11:28 by soel-mou          #+#    #+#             */
/*   Updated: 2024/01/10 23:11:31 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*uc_s;

	uc_s = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		uc_s[count] = 0;
		count++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	total_size = count * size;
	if (total_size / size != count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr != NULL)
		ft_bzero(ptr, total_size);
	return (ptr);
}
