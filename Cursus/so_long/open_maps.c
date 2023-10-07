/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:23 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 14:35:14 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_movement(t_so_long *s, int x, int y)
{
	if (s->map[s->player_y + y][s->player_x + x] == '1')
		return ;
	if (s->map[s->player_y + y][s->player_x + x] == 'E' && s->count_c == 0)
	{
		ft_printf("number of moves: %d\n!!VICTORYYY!!\n", s->count_step + 1);
		game_end(s);
	}
	if (s->map[s->player_y + y][s->player_x + x] == 'C')
		s->count_c--;
	s->count_step++;
	if (s->map[s->player_y][s->player_x] != 'E')
		s->map[s->player_y][s->player_x] = '0';
	s->player_y += y;
	s->player_x += x;
}

void	check_door(t_so_long *s, int a, int b)
{
	if (s->count_c == 0)
	{
		s->door = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/open_door.xpm", &a, &b);
	}
}

void	charackter_show(t_so_long *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (c == 'w')
		s->playerimg = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/char_up.xpm", &a, &b);
	if (c == 's')
		s->playerimg = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/char_down.xpm", &a, &b);
	if (c == 'a')
		s->playerimg = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/char_left.xpm", &a, &b);
	if (c == 'd')
		s->playerimg = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/char_right.xpm", &a, &b);
	if (!s->playerimg)
		return (ft_printf("Errorrrr\n"), game_end(s));
}

void	game_over(int a, t_so_long *s)
{
	if (a == 1)
		ft_printf("Game Over!!\n");
	game_end(s);
}

int	movement(int key, t_so_long *s)
{
	if (key == ESC)
		game_over(1, s);
	else if (key == W)
	{
		charackter_show(s, 'w');
		player_movement(s, 0, -1);
	}
	else if (key == S)
	{
		charackter_show(s, 's');
		player_movement(s, 0, 1);
	}
	else if (key == A)
	{
		charackter_show(s, 'a');
		player_movement(s, -1, 0);
	}
	else if (key == D)
	{
		charackter_show(s, 'd');
		player_movement(s, 1, 0);
	}
	check_door(s, 0, 0);
	return (1);
}
