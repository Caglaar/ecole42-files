/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <Mcaglar@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:27:53 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/09 11:30:30 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	counter;
	int	counter2;

	counter = 0;
	while (counter < size)
	{
		counter2 = counter + 1;
		while (counter2 < size)
		{
			if (tab[counter] > tab[counter2])
			{
				temp = tab[counter2];
				tab[counter2] = tab[counter];
				tab[counter] = temp;
			}
			counter2++;
		}
		counter++;
	}
}
