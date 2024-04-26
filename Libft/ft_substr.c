/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:09:19 by soel-mou          #+#    #+#             */
/*   Updated: 2023/11/24 15:58:13 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <limits.h>

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	char	*result;
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	else if (len + start > str_len)
		substr = (char *)malloc((str_len - start + 1) * sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	result = substr;
	while (*(str + start) && len-- > 0)
		*substr++ = *(str + start++);
	*substr = 0;
	return (result);
}
#include <stdio.h>

int main()
{
	printf("%s\n", ft_substr(NULL, 0, 4));
}