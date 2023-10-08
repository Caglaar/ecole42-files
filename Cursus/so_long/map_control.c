/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:55:15 by oakbulak          #+#    #+#             */
/*   Updated: 2023/10/05 18:04:02 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_count_control(t_so_long *s)
{
	if (s->count_p != 1 || s->count_c == 0 || s->count_e != 1
		|| s->count_n != 1)
		return (ft_printf("Missing character on map\n"), free_map(s));
	if (s->map_height == s->map_width)
		return (ft_printf("Not a rectangular map!!!\n"), free_map(s));
}

void	map_utils_control(t_so_long *s, char c, int y, int x)
{
	if (c == '1' || c == '0'
		|| c == 'C' || c == 'E'
		|| c == 'P' || c == 'N')
	{
		if (c == 'P')
		{
			s->player_y = y;
			s->player_x = x;
			s->count_p++;
		}
		if (c == 'C')
			s->count_c++;
		if (c == 'E')
			s->count_e++;
		if (c == 'N')
		{
			s->count_n++;
			s->enemy_x = x;
			s->enemy_y = y;
		}
	}
	else
		return (ft_printf("wrong map!!\n"), free_map(s));
}

void	map_travel(t_so_long *s, int x, int y)
{
	while (s->map[++y])
	{
		x = -1;
		while (s->map[y][++x])
		{
			map_utils_control(s, s->map[y][x], y, x);
		}
	}
	map_count_control(s);
}

void	map_side_control(t_so_long *s, int x, int y)
{
	if (s->map[++y])
		while (s->map[y][++x])
			if (s->map[y][x] != '1' || s->map[y][x] == ' ')
				return (ft_printf("Error\n"), free_map(s));
	x = -1;
	while (s->map[s->map_height - 2][++x])
		if (s->map[s->map_height - 2][x] != '1' || s->map[y][x] == ' ')
			return (ft_printf("Error\n"), free_map(s));
	while (y <= s->map_height - 2 && s->map[y][0])
	{
		if (s->map[y][0] != '1' || s->map[y][x] == ' ')
			return (ft_printf("Error\n"), free_map(s));
		y++;
	}
	y = -1;
	while (++y <= s->map_height - 2 && s->map[y][s->map_width - 2])
		if (s->map[y][s->map_width - 2] != '1' || s->map[y][x] == ' ')
			return (ft_printf("Error\n"), free_map(s));
	map_travel(s, -1, -1);
}

void	map_make(t_so_long *s, char *tmp_map)
{
	s->map = ft_split(tmp_map, '\n');
	if (!s->map)
		return (ft_printf("Error\n"), free_map(s));
	map_side_control(s, -1, -1);
	map_dc_control(s, ft_split(tmp_map, '\n'));
	free(tmp_map);
}
