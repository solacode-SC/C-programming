/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 02:14:17 by soel-mou          #+#    #+#             */
/*   Updated: 2024/03/06 02:14:19 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2, int v1, int v2);
char	*until_nl(char *s);
char	*after_nl(char *s);
void	copy_string(char *src, char *dest);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif
