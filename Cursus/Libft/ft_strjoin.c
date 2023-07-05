/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:57:46 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:59:36 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	leng;
	unsigned int	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (leng + 1));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
