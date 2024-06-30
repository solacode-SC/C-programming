
#include "ft_printf.h"

int	ft_ohhhhhyeeeh(va_list args, char c, int *i)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'X')
		counter += ft_putnbr_base(va_arg(args, unsigned int), HEX_UPPER);
	else if (c == 'x')
		counter += ft_putnbr_base(va_arg(args, unsigned int), HEX_LOWER);
	else if (c == 'p')
		counter += ft_putstr("0x") + ft_putnbr_base(va_arg(args, unsigned long),
				HEX_LOWER);
	else if (c == 'u')
		counter += ft_putnbr(va_arg(args, unsigned int));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == '%')
		counter += ft_putchar('%');
	else
		(*i)--;
	return (counter);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		index;

	va_start(args, input);
	index = -1;
	i = 0;
	while (input[++index])
	{
		if (input[index] == '%')
		{
			index++;
			if (!input[index])
				return (i);
			i += check_type(args, input[index], &index);
		}
		else
			i += ft_putchar(input[index]);
	}
	va_end(args);
	return (i);
}

int main()
{
	printf("%s" , "");
}
