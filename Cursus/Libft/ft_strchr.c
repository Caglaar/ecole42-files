/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:23:08 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:31:35 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		if (s[counter] == (unsigned char)c)
			return (&((char *)s)[counter]);
		counter++;
	}
	if ((unsigned char)c == s[counter])
		return (&((char *)s)[counter]);
	return (NULL);
}
