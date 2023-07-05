/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:20:57 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:21:19 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	leng;
	size_t	counter;

	counter = 0;
	leng = ft_strlen(dest);
	if (size - 1 > leng && size > 0)
	{
		while (src[counter] != '\0' && size - 1 > leng + counter)
		{
			dest[counter + leng] = src[counter];
			counter++;
		}
		dest[leng + counter] = 0;
	}
	if (leng >= size)
		leng = size;
	return (leng + ft_strlen(src));
}
