/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:05 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/16 15:02:05 by mcaglar          ###   ########.tr       */
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

char	*ft_strstr(char *str, char *to_find)
{
	int	lenhan;
	int	lenned;
	int	i;
	int	j;

	lenned = ft_strlen(to_find);
	lenhan = ft_strlen(str);
	i = 0;
	while (i <= (lenhan - lenned))
	{
		j = 0;
		while (j < lenned)
		{
			if ((str[i + j]) != to_find[j])
				break ;
			j++;
		}
		if (j == lenned)
			return (str + i);
		i++;
	}
	return (0);
}
