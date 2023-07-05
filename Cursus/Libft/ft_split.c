/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:08:45 by mcaglar           #+#    #+#             */
/*   Updated: 2023/07/05 12:20:53 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_word_counter(const char *s, char control)
{
	unsigned int	word;

	word = 0;
	while (*s)
	{
		if (*s == control)
			s++;
		else
		{
			while (*s != control && *s)
				s++;
			word++;
		}
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(ft_word_counter(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}
