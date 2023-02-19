/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <m>                                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:15:15 by mcaglar           #+#    #+#             */
/*   Updated: 2023/02/17 16:56:58 by mcaglar          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	result = nb;
	while (++i < power)
	{
		result = result * nb;
	}
	return (result);
}
