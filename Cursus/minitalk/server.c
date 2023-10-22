/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:12:04 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/22 14:32:47 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int s)
{
	static char	c = 0;
	static int	i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		ft_putchar_fd(c, 1);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("\n\t\t\t\t --------------------\n", 1);
	ft_putstr_fd("\t\t\t\t| Process ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("  |", 1);
	ft_putstr_fd("\n\t\t\t\t --------------------\n", 1);
	ft_putstr_fd("\t\t\t ------------SERVER CONSOLE------------\n", 1);
	ft_putstr_fd("Message\n", 1);
	ft_putstr_fd("-------\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
