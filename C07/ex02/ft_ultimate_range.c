/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:56:46 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/24 11:29:55 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(int min, int max)
{
	int	i;

	i = (max - min);
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(ft_size(min, max) * sizeof(int));
	i = 0;
	if (min >= max)
		return (0);
	if (!arr)
		return (-1);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	*range = arr;
	return (i);
}
