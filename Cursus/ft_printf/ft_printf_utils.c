/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:56:28 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/15 12:14:05 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int w)
{
	int	leng;

	leng = 0;
	if (w == 0)
		return (write(1, "0", 1));
	if (w == -2147483648)
		return (write(1, "-2147483648", 11));
	if (w < 0)
	{
		leng += write(1, "-", 1);
		w *= -1;
	}
	if (w >= 10)
		leng += ft_int(w / 10);
	write(1, &"0123456789"[w % 10], 1);
	return (leng + 1);
}

int	ft_unsigned(unsigned int w)
{
	int	leng;

	leng = 0;
	if (w >= 10)
		leng += ft_unsigned(w / 10);
	write(1, &"0123456789"[w % 10], 1);
	return (leng + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_hex(unsigned int d, char w)
{
	int	leng;

	leng = 0;
	if (d >= 16)
		leng += ft_hex(d / 16, w);
	if (w == 'X')
		write(1, &"0123456789ABCDEF"[d % 16], 1);
	if (w == 'x')
		write(1, &"0123456789abcdef"[d % 16], 1);
	return (leng + 1);
}

int	ft_point(unsigned long w, int i)
{
	int	leng;

	leng = 0;
	if (i == 1)
	{
		leng += write(1, "0x", 2);
		i = 0;
	}
	if (w >= 16)
		leng += ft_point(w / 16, i);
	write(1, &"0123456789abcdef"[w % 16], 1);
	return (leng + 1);
}
