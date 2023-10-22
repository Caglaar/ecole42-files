/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:12:09 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/22 14:32:53 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 128;

	(void)context;
	if (sig == SIGUSR1)
		c += i;
	i /= 2;
	if (i == 0)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	pid = getpid();
	ft_putstr_fd("\n\t\t\t\t --------------------\n", 1);
	ft_putstr_fd("\t\t\t\t| Process ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("  |", 1);
	ft_putstr_fd("\n\t\t\t\t --------------------\n", 1);
	ft_putstr_fd("\t\t\t ------------SERVER CONSOLE------------\n", 1);
	ft_putstr_fd("Message\n", 1);
	ft_putstr_fd("-------\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
