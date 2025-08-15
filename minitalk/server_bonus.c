/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:23:13 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/15 11:43:59 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void	write_pid(int pid)
{
	if (pid >= 10)
		write_pid(pid / 10);
	write(1, &((char []){'0' + (pid % 10)}), 1);
}

static void	reset_state(pid_t pid, pid_t *lpid, unsigned char *c, int *bit)
{
	*lpid = pid;
	*c = 0;
	*bit = 0;
}

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c = 0;
	static int				bit = 0;
	static pid_t			last_pid = 0;

	(void)ucontext;
	if (last_pid != info->si_pid)
		reset_state(info->si_pid, &last_pid, &c, &bit);
	c = (c << 1) | (sig == SIGUSR1);
	if (++bit == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			if (kill(info->si_pid, SIGUSR2) == -1)
				write(2, "Error: Failed to end transmission\n", 34);
		}
		bit = 0;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		write(2, "Error: Failed to send ACK\n", 26);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID: ", 12);
	write_pid(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
}
