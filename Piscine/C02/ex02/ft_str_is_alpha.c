/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:48:19 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/10 13:28:44 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	door;
	int	counter;

	counter = 0;
	door = 1;
	while (str[counter] != '\0' && door == 1)
	{
		if ((str[counter] <= 'Z' && str[counter] >= 'A'))
			door = 1;
		else if ((str[counter] <= 'z' && str[counter] >= 'a'))
			door = 1;
		else
			door = 0;
		counter++;
	}
	return (door);
}
