/* *************void	ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);

void	signal_handler(int sig)******************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 00:00:00 by mecetink          #+#    #+#             */
/*   Updated: 2025/08/01 21:08:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int sig)
{
	static int bit_count = 0;
	static int current_char = 0;
	
	if (sig == SIGUSR1)
		current_char = (current_char << 1) | 1;
	else
		current_char = current_char << 1;

	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == 0)
		{
			ft_putchar_fd('\n', 1);
			ft_printf("Message received.\n");
		}
		else
			ft_putchar_fd(current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	ft_printf("Waiting for messages...\n");

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
		pause();

	return (0);
}