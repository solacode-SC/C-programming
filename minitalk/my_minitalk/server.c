#include "minitalk.h"

t_data g_data = {0};

void signal_handler(int signum)
{
	// Shift left the current character
	g_data.current_char <<= 1;

	// If SIGUSR2, set the least significant bit to 1
	if (signum == SIGUSR2)
		g_data.current_char |= 1;

	// Increment the bit counter
	g_data.bit_count++;

	// If we have received 8 bits (1 byte), print the character
	if (g_data.bit_count == 8)
	{
		write(1, &g_data.current_char, 1);
		g_data.bit_count = 0;
		g_data.current_char = 0;
	}
}

int main(void)
{
	struct sigaction sa;
	int pid;

	pid = getpid();
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;  // Simplified
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	write(1, "Server PID: ", 12);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);

	// Infinite loop waiting for signals
	while (1)
		pause();

	return (0);
}
