/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:07:23 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 13:08:39 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pntr;

	pntr = malloc(size * nmemb);
	if (!(pntr))
		return (NULL);
	ft_bzero(pntr, (nmemb * size));
	return (pntr);
}
