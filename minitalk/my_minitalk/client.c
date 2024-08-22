#include "minitalk.h"

void send_signal(int pid, char c)
{
	for (int i = 7; i >= 0; i--)
	{
		// Send SIGUSR2 if the current bit is 1, otherwise send SIGUSR1
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100); // Reduced delay for quicker communication
	}
}

int main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		write(1, "Usage: ./client [PID] [MESSAGE]\n", 32);
		return (1);
	}

	pid = ft_atoi(av[1]);
	msg = av[2];

	// Send each character of the message to the server
	while (*msg)
	{
		send_signal(pid, *msg);
		msg++;
	}

	// Send a newline character at the end
	send_signal(pid, '\n');

	return (0);
}
