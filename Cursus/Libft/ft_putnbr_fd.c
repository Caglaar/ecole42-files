/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:25:41 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 13:26:41 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	if (fd < 0)
		return ;
	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		c = nb % 10 + '0';
		write(fd, &c, 1);
	}
}
