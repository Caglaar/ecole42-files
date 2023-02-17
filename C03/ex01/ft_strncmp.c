/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:05:44 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 16:39:07 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned int	door;

	door = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && door == 0 && i < n)
	{
		if (s1[i] > s2[i])
			door = 1;
		if (s1[i] < s2[i])
			door = -1;
		i++;
	}
	if (door == 0)
		return (0);
	else if (door == 1)
		return (1);
	else
		return (-1);
}
