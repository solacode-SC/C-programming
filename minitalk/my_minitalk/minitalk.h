#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	char	current_char;
	int		bit_count;
}			t_data;

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);

#endif
