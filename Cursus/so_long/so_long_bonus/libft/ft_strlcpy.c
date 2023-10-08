/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:28:04 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:28:07 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	k = 0;
	while (src[k] != '\0' && k < dstsize - 1)
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (i);
}
