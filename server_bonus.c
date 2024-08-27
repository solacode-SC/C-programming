/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:04:52 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/27 02:12:05 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		g_data.byte = g_data.byte + (1 << g_data.shift);
	g_data.shift++;
	if (g_data.shift == 8)
	{
		write(1, &g_data.byte, 1);
		if (g_data.byte == '\0')
		{
			write(1, "\n", 1);
			kill((int)info->si_pid, SIGUSR2);
		}
		g_data.byte = 0;
		g_data.shift = 0;
	}
	kill((int)info->si_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	g_data.sa.sa_flags = SA_SIGINFO;
	g_data.sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &g_data.sa, NULL);
	sigaction(SIGUSR2, &g_data.sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
