#include "minitalk.h"

int main(int argc, char **argv)
{
    if (argc!= 3) {
        printf("Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
	while(*argv[2])
	{
        // send_signal(pid, *argv[2]);
        printf("Sent character '%c' to process %d\n", *argv[2], pid);
        // Wait for 1 second to allow the receiver to process the signal
        sleep(1);
        argv[2]++;
    }
	return 0;
}	