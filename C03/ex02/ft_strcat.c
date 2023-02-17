/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:14:41 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 13:31:01 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	lenght;

	lenght = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[lenght] = src[i];
		lenght++;
		i++;
	}
	dest[lenght] = '\0';
	return (dest);
}
