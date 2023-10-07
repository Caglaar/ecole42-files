/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:22:28 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:22:30 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_end(t_so_long *s)
{
	ft_malloc_error(s->map);
	if (s->background)
		mlx_destroy_image(s->mlx_ptr, s->background);
	if (s->coin)
		mlx_destroy_image(s->mlx_ptr, s->coin);
	if (s->door)
		mlx_destroy_image(s->mlx_ptr, s->door);
	if (s->playerimg)
		mlx_destroy_image(s->mlx_ptr, s->playerimg);
	if (s->wall)
		mlx_destroy_image(s->mlx_ptr, s->wall);
	if (s->enemyimg)
		mlx_destroy_image(s->mlx_ptr, s->enemyimg);
	if (s->mlx_win)
		mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	exit(0);
}

void	free_map(t_so_long *s)
{
	ft_malloc_error(s->map);
	exit(0);
}
