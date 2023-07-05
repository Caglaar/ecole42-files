/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:40:48 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 17:38:30 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*container1;
	unsigned const char	*container2;

	container1 = (unsigned char *)s1;
	container2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*container1 != *container2)
			return (*container1 - *container2);
		n--;
		container1++;
		container2++;
	}
	return (0);
}
