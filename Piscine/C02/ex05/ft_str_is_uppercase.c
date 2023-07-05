/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:14:10 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/10 14:20:40 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	counter;
	int	door;

	door = 1;
	counter = 0;
	while (str[counter] != '\0' && door == 1)
	{
		if (str[counter] >= 'A' && str[counter] <= 'Z')
			door = 1;
		else
			door = 0;
		counter++;
	}
	return (door);
}
