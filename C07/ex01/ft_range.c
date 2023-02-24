/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:24:04 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/23 12:51:24 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(int min, int max)
{
	int	i;

	i = (max - min);
	return (i);
}

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(ft_size(min, max) * sizeof(int));
	i = 0;
	if (min >= max)
		return (NULL);
	if (!arr)
		return (NULL);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
