/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:25:40 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:25:42 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*p1;

	p = (unsigned char *)s1;
	p1 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((p[i] == p1[i]) && i < n - 1)
		i++;
	return (p[i] - p1[i]);
}
