#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>


void handle_sigint(int sig)
{
	printf("Caught signal %d\n", sig);
}

int main()
{
	signal(SIGINT, handle_sigint);
	printf("Hello World\n");
	sleep(0);
	return 0;
}
