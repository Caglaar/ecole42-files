/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:40:40 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:45:04 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		counter;

	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		h = haystack;
		n = needle;
		counter = 0;
		while (n[counter] == h[counter] && n[counter] && len - counter > 0)
			counter++;
		if (n[counter] == '\0')
			return ((char *) haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
