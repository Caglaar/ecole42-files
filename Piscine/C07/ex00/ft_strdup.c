/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:28:50 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/23 12:46:37 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		leng;
	char	*copy;

	copy = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	leng = 0;
	if (!copy)
		return (0);
	while (leng <= ft_strlen(src))
	{
		copy[leng] = src[leng];
		leng++;
	}
	return (copy);
}
