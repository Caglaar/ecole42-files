/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:39:26 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/23 14:13:39 by mcaglar          ###   ########.tr       */
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

int	ft_find_lenght(int size, char **str, char *sep)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	while (i < size)
	{
		lenght += ft_strlen(str[i]);
		i++;
	}
	lenght += (size - 1) * (ft_strlen(sep));
	return (lenght);
}

void	ft_append(char *arr, char *str, int *i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		arr[*i] = str[j];
		j++;
		*i += 1;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		lenght;
	int		i;
	int		j;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	j = 0;
	i = 0;
	lenght = ft_find_lenght(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!arr)
		return (0);
	while (j < size)
	{
		ft_append(arr, strs[j], &i);
		if (j < (size -1))
			ft_append(arr, sep, &i);
		j++;
	}
	arr[lenght] = '\0';
	return (arr);
}
