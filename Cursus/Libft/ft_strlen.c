/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:34 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 17:43:15 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	leng;
	int	i;

	i = 0;
	leng = 0;
	while (s[i] != '\0')
	{
		leng++;
		i++;
	}
	return (leng);
}
