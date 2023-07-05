/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:57:48 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 14:18:16 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*buffer1;
	unsigned char	*buffer2;
	size_t			counter;

	if (!dest && !src)
		return (NULL);
	buffer1 = (unsigned char *)dest;
	buffer2 = (unsigned char *)src;
	counter = 0;
	if (buffer1 > buffer2)
	{
		while (n-- > 0)
			buffer1[n] = buffer2[n];
	}
	else
	{
		while (n > counter)
		{
			buffer1[counter] = buffer2[counter];
			counter++;
		}
	}
	return (dest);
}
