#include "minitalk.h"

t_data	g_data = {0};

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_data.current_char <<= 1;
	}
	else if (signum == SIGUSR2)
	{
		g_data.current_char <<= 1;
		g_data.current_char |= 1;
	}
	g_data.bit_count++;
	if (g_data.bit_count == 8)
	{
		write(1, &g_data.current_char, 1);
		g_data.bit_count = 0;
		g_data.current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID :\n", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}




#include "../include/minitalk.h"

t_vars	g_vars;

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		g_vars.byte = g_vars.byte + (1 << g_vars.shift);
	g_vars.shift++;
	if (g_vars.shift == 8)
	{
		ft_putchar_fd(g_vars.byte, 1);
		if (g_vars.byte == '\0')
			ft_putchar_fd('\n', 1);
		g_vars.byte = 0;
		g_vars.shift = 0;
	}
	kill((int)info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	g_vars.sa.sa_flags = SA_SIGINFO;
	g_vars.sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &g_vars.sa, NULL);
	sigaction(SIGUSR2, &g_vars.sa, NULL);
	while (1)
		sleep(1);
	return (0);
}