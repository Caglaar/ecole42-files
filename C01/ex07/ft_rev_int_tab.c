/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:08:45 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/09 11:12:38 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	counter;
	int	container;
	int	size_copy;

	counter = 0;
	size_copy = size;
	while (counter < (size / 2))
	{
		container = tab[counter];
		tab[counter] = tab[size_copy - 1];
		tab[size_copy - 1] = container;
		counter++;
		size_copy--;
	}
}
