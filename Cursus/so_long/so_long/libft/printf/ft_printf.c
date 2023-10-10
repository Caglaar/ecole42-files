/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:30:42 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:30:44 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (s[i] != '\0')
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_flag(char *s, int i)
{
	if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's' || s[i + 1] == 'p'
			|| s[i + 1] == 'd' || s[i + 1] == 'i' || s[i + 1] == 'u'
			|| s[i + 1] == 'x' || s[i + 1] == 'X' || s[i + 1] == '%'))
	{
		return (1);
	}
	return (0);
}

int	ft_format(va_list *arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((*arg), int)));
	else if (c == 's')
		return (ft_string(va_arg((*arg), char *)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg((*arg), int)));
	else if (c == 'p')
		return (ft_point(va_arg((*arg), unsigned long long int), 1));
	else if (c == 'u')
		return (ft_unnbr(va_arg((*arg), unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg((*arg), unsigned long int), 'x'));
	else if (c == 'X')
		return (ft_hex(va_arg((*arg), unsigned long int), 'X'));
	else if (c == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		res;
	int		tmp;

	i = -1;
	res = 0;
	va_start(arg, str);
	while (str[++i])
	{
		if (ft_flag((char *)str, i))
		{
			tmp = ft_format(&arg, str[++i]);
			if (tmp == -1)
				return (-1);
			res += tmp;
		}
		else
		{
			res++;
			if (ft_putchar(str[i]) == -1)
				return (-1);
		}
	}
	return (res);
}
