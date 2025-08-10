/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:04:50 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/10 15:55:48 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static sig_atomic_t	g_ack = 0;

static int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result);
}

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		while (!g_ack)
			;
		g_ack = 0;
	}
}

static void	handle_ack(int sig __attribute__((unused)))
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		write(1, "[ACK]: Message sent successfully\n", 34);
}

static void	send_str(int pid, const char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}
int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0')
	{
		write(2, "Usage: ./client [pid] [message]\n", 32);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Error: Invalid PID or doesn't exist\n", 36);
		exit(EXIT_FAILURE);
	}
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = handle_ack;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
	|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	send_str(pid, argv[2]);
	return (0);
}
