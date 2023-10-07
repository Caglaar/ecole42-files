/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:32 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 16:22:11 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	steps(t_so_long *ptr)
{
	char	*steps;
	char	*tmp;

	tmp = ft_itoa(ptr->count_step);
	steps = ft_strjoin("Steps: ", tmp);
	mlx_string_put(ptr->mlx_ptr,
		ptr->mlx_win, 10, 30, 0x00FFFFFF, steps);
	free(steps);
	free(tmp);
}

int	enemy_anger(t_so_long *game, int a, int b)
{
	game->adrenaline++;
	if (game->adrenaline == 10)
		game->adrenaline = 0;
	else
		return (0);
	if (game->map[game->enemy_y][game->enemy_x - 1] == '1')
		game->wallcheck = 0;
	if (game->map[game->enemy_y][game->enemy_x + 1] == '1')
		game->wallcheck = 1;
	if (game->wallcheck && game->map[game->enemy_y][game->enemy_x - 1] != '1')
	{
		game->enemy_x--;
		game->enemyimg = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/ghost_left.xpm", &a, &b);
	}
	else if (!game->wallcheck
		&& game->map[game->enemy_y][game->enemy_x + 1] != '1')
	{
		game->enemy_x++;
		game->enemyimg = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/ghost_right.xpm", &a, &b);
	}
	return (1);
}

int	hollmovement(t_so_long *s)
{
	open_win(s, -1, -1);
	steps(s);
	if (s->player_x == s->enemy_x
		&& s->player_y == s->enemy_y)
	{
		ft_printf("Game Over!!");
		game_end(s);
	}
	if (!enemy_anger(s, 0, 0))
		return (0);
	if (s->map[s->enemy_y][s->enemy_x] != 'C' &&
			s->map[s->enemy_y][s->enemy_x] != 'E')
		s->map[s->enemy_y][s->enemy_x] = 'N';
	return (0);
}
