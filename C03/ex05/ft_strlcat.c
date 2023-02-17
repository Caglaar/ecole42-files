/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:07:33 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 15:27:11 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lengd;
	unsigned int	lengs;

	i = 0;
	lengd = ft_strlen(dest);
	lengs = ft_strlen(src);
	j = lengd;
	if (size == 0 || size <= lengd)
		return (lengs + size);
	while (src[i] != '\0' && i < size - lengd - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (lengd + lengs);
}
