/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:32:01 by soel-mou          #+#    #+#             */
/*   Updated: 2024/01/08 15:32:03 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
int		print_ptr(unsigned long value, int asc);
int		print_unsgd(unsigned int nb);
int		print_str(char *s);
int		print_int(int n);
int		print_char(char c);
int		print_hex(unsigned int value, int asc);
void	*ft_calloc(size_t count, size_t size);

#endif
