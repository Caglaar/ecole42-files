/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:20:09 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 13:42:44 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# define W		13
# define S		1
# define A		0
# define D		2
# define ESC	53
# define P		64

typedef struct s_so_long
{
	char	**map;
	int		map_width;
	int		map_height;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_step;
	int		count_n;
	int		enemy_x;
	int		enemy_y;
	int		adrenaline;
	int		wallcheck;
	int		cointimer;
	int		player_x;
	int		player_y;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*playerimg;
	void	*enemyimg;
	void	*wall;
	void	*background;
	void	*coin;
	void	*door;
}	t_so_long;

typedef struct s_control
{
	int	is_the_door_accessible;
	int	the_amount_of_coins_we_can_reach;
}	t_control;

void	map_widht_control(t_so_long *s, char *line, char *tmp_map);
void	map_dc_control(t_so_long *s, char	**map);
void	map_travel(t_so_long *s, int x, int y);
void	map_side_control(t_so_long *s, int x, int y);
void	map_make(t_so_long *s, char *tmp_map);
void	map_string_control(char *str, t_so_long *s);
void	map_ber_control(char *str, t_so_long *s);
void	player_movement(t_so_long *s, int x, int y);
void	check_door(t_so_long *s, int a, int b);
void	charackter_show(t_so_long *s, char c);
void	game_over(int a, t_so_long *s);
int		movement(int key, t_so_long *s);
void	open_win(t_so_long *s, int x, int y);
void	map_shows1(t_so_long *s);
void	game_end(t_so_long *s);
void	free_map(t_so_long *s);
char	*config_map(t_so_long *s, int *fd, char *str);
int		hollmovement(t_so_long *s);

#endif
