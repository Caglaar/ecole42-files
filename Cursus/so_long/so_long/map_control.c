/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:15 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 16:53:40 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_count_control(t_so_long *s)
{
	if (s->count_p != 1 || s->count_c == 0 || s->count_e != 1)
		return (ft_printf("missing character on map\n"), free_map(s));
	if (s->map_height == s->map_width)
		return (ft_printf("Not a rectangular map!!!\n"), free_map(s));
}

void	map_utils_control(t_so_long *s, int x, int y)
{
	while (s->map[++y])
	{
		x = -1;
		while (s->map[y][++x])
		{
			if (s->map[y][x] == '1' || s->map[y][x] == '0'
				|| s->map[y][x] == 'C' || s->map[y][x] == 'E'
				|| s->map[y][x] == 'P')
			{
				if (s->map[y][x] == 'P')
				{
					s->player_y = y;
					s->player_x = x;
					s->count_p++;
				}
				if (s->map[y][x] == 'C')
					s->count_c++;
				if (s->map[y][x] == 'E')
					s->count_e++;
			}
			else
				return (ft_printf("wrong map!!\n"), free_map(s));
		}
	}
	map_count_control(s);
}

void	map_side_control(t_so_long *s, int x, int y)
{
	if (s->map[++y])
		while (s->map[y][++x])
			if (s->map[y][x] != '1')
				return (ft_printf("Error\n"), free_map(s));
	x = -1;
	while (s->map[s->map_height - 2][++x])
		if (s->map[s->map_height - 2][x] != '1')
			return (ft_printf("Error\n"), free_map(s));
	while (y <= s->map_height - 2 && s->map[y][0])
	{
		if (s->map[y][0] != '1')
			return (ft_printf("Error\n"), free_map(s));
		y++;
	}
	y = -1;
	while (++y <= s->map_height - 2 && s->map[y][s->map_width - 2])
		if (s->map[y][s->map_width - 2] != '1')
			return (ft_printf("Error\n"), free_map(s));
	map_utils_control(s, -1, -1);
}

void	map_make(t_so_long *s, char *tmp_map)
{
	s->map = ft_split(tmp_map, '\n');
	if (!s->map)
		return (ft_printf("Not opened map"), free(tmp_map), exit(1));
	map_side_control(s, -1, -1);
	map_dc_control(s, ft_split(tmp_map, '\n'));
	free(tmp_map);
}
