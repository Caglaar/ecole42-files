/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_maps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:15 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 16:53:40 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_win(t_so_long *s, int x, int y)
{
	ft_printf("number of moves: %d\n", s->count_step);
	while (s->map[++y])
	{
		x = -1;
		while (s->map[y][++x])
		{
			mlx_put_image_to_window(s->mlx_ptr,
				s->mlx_win, s->background, x * P, y * P);
			if (s->map[y][x] == '1')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win,
					s->wall, x * P, y * P);
			if (s->map[y][x] == '0')
				mlx_put_image_to_window(s->mlx_ptr,
					s->mlx_win, s->background, x * P, y * P);
			if (s->map[y][x] == 'E')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->door,
					x * P, y * P);
			if (s->map[y][x] == 'C')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->coin,
					x * P, y * P);
		}
	}
	mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->playerimg,
		s->player_x * P, s->player_y * P);
}

int	close_window(t_so_long *s)
{
	ft_printf("Game Over!!");
	game_end(s);
	return (0);
}

void	map_shows1(t_so_long *s)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	s->mlx_ptr = mlx_init();
	s->mlx_win = mlx_new_window(s->mlx_ptr, (s->map_width - 1) * P,
			(s->map_height - 1) * P, "PACMAN By Caglaar");
	s->playerimg = mlx_xpm_file_to_image(s->mlx_ptr,
			"textures/char_right.xpm", &a, &b);
	s->background = mlx_xpm_file_to_image(s->mlx_ptr,
			"textures/background.xpm", &a, &b);
	s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
			"textures/coin.xpm", &a, &b);
	s->door = mlx_xpm_file_to_image(s->mlx_ptr,
			"textures/door.xpm", &a, &b);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr,
			"textures/wall.xpm", &a, &b);
	if (!s->mlx_ptr || !s->mlx_win || !s->playerimg
		|| !s->background || !s->coin || !s->door || !s->wall)
		return (ft_printf("Errrrrrror\n"), game_end(s));
	open_win(s, -1, -1);
	mlx_hook(s->mlx_win, 2, 0, movement, s);
	mlx_hook(s->mlx_win, 17, 0, close_window, s);
	mlx_loop(s->mlx_ptr);
}
