/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:06:05 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/10 14:12:59 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	counter;
	int	door;

	door = 1;
	counter = 0;
	while (str[counter] != '\0' && door == 1)
	{
		if (str[counter] >= 'a' && str[counter] <= 'z')
			door = 1;
		else
			door = 0;
		counter++;
	}
	return (door);
}
