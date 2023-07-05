/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:36:33 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/06 16:00:09 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_exit(char x, char y, char z)
{
	while (z <= '9')
	{
		write(1, &x, 1);
		write(1, &y, 1);
		write(1, &z, 1);
		z++;
		if (x != '7')
			write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	x;
	int	y;
	int	z;

	x = '0';
	while (x <= '7')
	{
		y = x + 1;
		while (y <= '8')
		{
			z = y + 1;
			ft_write_exit(x, y, z);
			y++;
		}
		x++;
	}
}
