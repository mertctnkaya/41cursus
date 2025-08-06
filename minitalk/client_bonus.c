/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:04:50 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/06 20:19:21 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static volatile sig_atomic_t	g_ack = 0;

static void	handle_ack(int sig __attribute__((unused)))
{
	g_ack = 1;
}

static void	send_bit(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(80);
}

static void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		send_bit(pid, (c >> i) & 1);
		usleep(50);
	}
	while (!g_ack)
		pause();
	g_ack = 0;
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

	if (argc != 3)
	{
		write(2, "\e[31mUsage: ./client_bonus [pid] [message]\e[0m\n", 48);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "\e[31mError: Invalid PID\e[0m\n", 29);
		return (1);
	}
	if (kill(pid, 0) == -1)
	{
		write(2, "\e[31mError: PID does not exist\e[0m\n", 36);
		return (1);
	}
	sa.sa_handler = handle_ack;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	write(1, "\e[33mSending message:\e[0m <", 27);
	write(1, argv[2], ft_strlen(argv[2]));
	write(1, ">\n", 3);
	send_str(pid, argv[2]);
	write(1, "\e[32mMessage sent successfully!\e[0m\n", 36);
	return (0);
}
