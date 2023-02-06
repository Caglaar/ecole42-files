/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:23:43 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/06 11:53:31 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_exam(int x, int y, int door)
{
	ft_putchar(48 + x / 10);
	ft_putchar(48 + x % 10);
	ft_putchar(' ');
	ft_putchar(48 + y / 10);
	ft_putchar(48 + y % 10);
	if (door == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	x;
	int	y;
	int	door;

	x = 0;
	door = 0;
	while (door == 0 && x <= 98)
	{
		y = x + 1;
		while (y <= 99)
		{
			if (x == 98 && y == 99)
			{
				door = 1;
			}
			ft_write_exam(x, y, door);
			y++;
		}
		x++;
	}
}
