/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:02:16 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/10 16:33:06 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	counter;
	int	door;

	door = 1;
	counter = 0;
	while (str[counter] != '\0' && door == 1)
	{
		if (str[counter] >= 32 && str[counter] <= 126)
			door = 1;
		else
			door = 0;
		counter++;
	}
	return (door);
}
