/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:30:44 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/10 14:04:58 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	counter;
	int	door;

	door = 1;
	counter = 0;
	while (str[counter] != '\0' && door == 1)
	{
		if (str[counter] >= 48 && str[counter] <= 57)
			door = 1;
		else
			door = 0;
		counter++;
	}
	return (door);
}
