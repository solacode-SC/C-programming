/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:52:21 by soel-mou          #+#    #+#             */
/*   Updated: 2023/12/05 21:29:08 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		len;
	size_t		count;
	char		*str_allocted;

	len = 0;
	len = ft_strlen(s1);
	str_allocted = (char *)malloc(len + 1);
	if (str_allocted == NULL)
		return (NULL);
	count = 0;
	while (s1 && s1[count])
	{
		str_allocted[count] = s1[count];
		count++;
	}
	str_allocted[count] = '\0';
	return (str_allocted);
}
