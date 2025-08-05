#define _POSIX_C_SOURCE 201701L
#include <signal.h>
#include <unistd.h>

static void	write_pid(int pid)
{
	if (pid >= 10)
		write_pid(pid / 10);
	write(1, &((char[]){'0' + (pid % 10)}), 1);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char c = 0;
	static int bit = 0;

	(void)context;
	c = (c << 1) | (sig == SIGUSR1);
	if (++bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			write(1, "\n", 1);
		bit = 0;
		c = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	write(1, "Server PID: ", 13);
	write_pid(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}