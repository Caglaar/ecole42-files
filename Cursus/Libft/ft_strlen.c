/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:34 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/04 15:10:01 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	leng;

	leng = 0;
	while (*s)
		leng++;
	return (leng);
}
