/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:04:34 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/27 02:14:05 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"

typedef struct s_data
{
	int					shift;
	char				byte;
	int					wait;
	struct sigaction	sa;

}			t_data;

void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_wait(int sig);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
#endif
