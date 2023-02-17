/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 15:04:40 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 13:00:07 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	counter;
	int	door;

	counter = 0;
	door = 0;
	while ((s1[counter] != '\0' || s2[counter] != '\0') && door == 0)
	{
		if (s1[counter] == s2[counter])
			door = 0;
		else if (s1[counter] > s2[counter])
			door = 1;
		else if (s1[counter] < s2[counter])
			door = -1;
		counter++;
	}
	if (door == 1)
		return (1);
	else if (door == 0)
		return (0);
	else
		return (-1);
}
