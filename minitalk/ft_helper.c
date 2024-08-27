
#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long int	result;
	long int	result2;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result2 = result;
		result = result * 10 + (*str++ - '0');
		if (result < result2 && sign == -1)
			return (0);
		if (result < result2 && sign == 1)
			return (-1);
	}
	return (sign * result);
}

void	ft_putnbr(int n)
{
	char	num;


	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		num = '0' + n % 10;
		write(1, &num, 1);
	}
	if (n < 10)
	{
		num = '0' + n;
		write(1, &num, 1);
	}
}
