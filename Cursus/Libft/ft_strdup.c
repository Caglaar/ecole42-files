/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:45:55 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:47:05 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	counter;

	counter = ft_strlen(s) + 1;
	str = malloc(sizeof(char) * counter);
	if (!(str))
		return (NULL);
	str[counter] = '\0';
	while (counter--)
		str[counter] = s[counter];
	return (str);
}
