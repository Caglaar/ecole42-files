/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:30:49 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:30:50 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkpoint(unsigned long long int x)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	if (x < 0)
	{
		i += ft_putchar('-');
		x *= -1;
	}
	if (x >= 16)
	{
		i += checkpoint(x / 16);
		i += ft_putchar(hex[x % 16]);
	}
	else
		i += ft_putchar(hex[x % 16]);
	return (i);
}

int	ft_point(unsigned long long int x, int a)
{
	int	i;

	i = 0;
	if (a == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i += 2;
	}
	i += checkpoint(x);
	return (i);
}

int	ft_hex(unsigned int a, char c)
{
	int	ret;
	int	tmp;

	tmp = 0;
	ret = 0;
	if (a >= 16)
	{
		tmp = ft_hex(a / 16, c);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	if (c == 'X')
	{
		tmp = write(1, &"0123456789ABCDEF"[a % 16], 1);
		if (tmp == -1)
			return (-1);
	}
	if (c == 'x')
	{
		tmp = write(1, &"0123456789abcdef"[a % 16], 1);
		if (tmp == -1)
			return (-1);
	}
	return (ret + tmp);
}

int	ft_putnbr(long int nb)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (nb < 0)
	{
		i++;
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		tmp = ft_putnbr(nb / 10);
		if (tmp == -1)
			return (-1);
		nb = nb % 10;
		i += tmp;
	}
	if (ft_putchar(nb + 48) == -1)
		return (-1);
	return (i + 1);
}

int	ft_unnbr(unsigned int a)
{
	int	ret;
	int	temp;

	ret = 0;
	temp = 0;
	if (a >= 10)
	{
		temp += ft_unnbr(a / 10);
		if (temp == -1)
			return (-1);
		temp += ft_unnbr(a % 10);
		if (temp == -1)
			return (-1);
	}
	else
	{
		temp = write(1, &"0123456789"[a % 10], 1);
		if (temp == -1)
			return (-1);
	}
	return (ret + temp);
}
