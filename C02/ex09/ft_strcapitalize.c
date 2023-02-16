/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:11:27 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 10:03:22 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'A' && str[counter] <= 'Z')
				str[counter] += 32;
			counter++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	counter;
	int	control;

	counter = 0;
	control = 1;
	ft_strlowcase(str);
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'a' && str[counter] <= 'z')
		{
			if (control == 1)
				str[counter] -= 32;
			control = 0;
		}
		else if (str[counter] >= '0' && str[counter] <= '9')
			control = 0;
		else
			control = 1;
		counter++;
	}
	return (str);
}
