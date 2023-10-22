/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:12:28 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/22 14:58:12 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_direction(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr_fd("Signal Received\n", 1);
}

void	signal_push(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (j <= (int)ft_strlen(str))
	{
		i = 7;
		while (i >= 0)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR2, signal_direction);
		signal_push(pid, argv[2]);
		signal_push(pid, "\n");
	}
	return (0);
}
