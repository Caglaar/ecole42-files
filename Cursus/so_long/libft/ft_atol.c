/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:23:24 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:23:29 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if ((*str == '+' || *str == '-') && (!ft_isdigit(*++str)))
		return (0);
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (sign * res);
}
