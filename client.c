/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-mou <soel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 02:04:26 by soel-mou          #+#    #+#             */
/*   Updated: 2024/08/27 02:09:55 by soel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	print_and_exit(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	send_char(char c, int spid)
{
	while (g_data.shift <= 7)
	{
		g_data.wait = 0;
		if ((c >> g_data.shift) & 1)
		{
			if (kill(spid, SIGUSR1) == -1)
				print_and_exit("\nUnable to send to PID!!");
		}
		else
		{
			if (kill(spid, SIGUSR2) == -1)
				print_and_exit("\nUnable to send to PID!!");
		}
		g_data.shift++;
		while (!g_data.wait)
		{
			sleep(3);
			if (!g_data.wait)
				print_and_exit("\nTimeout, Somthing Wrong!");
		}
	}
	g_data.shift = 0;
}

void	bit_sent(int sig)
{
	if (sig == SIGUSR1)
		g_data.wait = 1;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (1);
	if (ft_atoi(av[1]) < 0)
		print_and_exit("\nWromg PID!!");
	pid = ft_atoi(av[1]);
	g_data.sa.sa_handler = bit_sent;
	g_data.sa.sa_flags = 0;
	signal(SIGINT, ft_wait);
	sigaction(SIGUSR1, &g_data.sa, NULL);
	i = 0;
	while (av[2][i])
		send_char(av[2][i++], pid);
	if (!av[2][i])
		send_char(av[2][i], pid);
	return (0);
}
