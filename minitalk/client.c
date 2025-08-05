/* *************int	ft_atoi(const char *str);
void	ft_printf(const char *format, ...);
void	ft_putstr_fd(char *s, int fd);

void	send_bit(int pid, int bit)************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 00:00:00 by mertctnkaya       #+#    #+#             */
/*   Updated: 2025/08/01 21:08:56 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void send_bit(int pid, int bit)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(200);
}

void send_char(int pid, char c)
{
	int bit;

	if (!pid || !c)
		return ;
	bit = 7;
	while (bit >= 0)
	{
		send_bit(pid, (c >> bit) & 1);
		bit--;
	}
}

void send_str(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int main(int argc, char **argv)
{
	int server_pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [pid] [message]\n", 2);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putstr_fd("Error: Invalid PID\n", 2);
		return (1);
	}
	ft_printf("Sending message: %s\n", argv[2]);
	send_str(server_pid, argv[2]);
	ft_printf("Message sent successfully!\n");
	return (0);
}