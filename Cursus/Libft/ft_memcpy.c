/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:53:46 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 12:56:28 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
		((unsigned char *)dest)[c1++] = ((char *)src)[c2++];
	return (dest);
}
