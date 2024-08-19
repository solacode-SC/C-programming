
#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "unistd.h"

typedef struct s_data
{
	int		byte;
	int		bit_count;
	char	current_char;

}			t_data;

void		ft_putnbr_fd(int n, int fd);
int			ft_atoi(const char *str);
#endif