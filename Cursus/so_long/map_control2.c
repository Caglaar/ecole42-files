/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaglar <mcaglar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:21:39 by mcaglar           #+#    #+#             */
/*   Updated: 2023/10/07 12:21:42 by mcaglar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explore_map(char **map, t_control *control, int y, int x)
{
	if (x == -1 || y == -1
		|| !map[y] || !map[y][x] || map[y][x] == '#' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		control->is_the_door_accessible = 1;
	else if (map[y][x] == 'C')
		control->the_amount_of_coins_we_can_reach++;
	map[y][x] = '#';
	explore_map(map, control, y + 1, x);
	explore_map(map, control, y - 1, x);
	explore_map(map, control, y, x + 1);
	explore_map(map, control, y, x - 1);
}

void	map_control5(t_so_long *s, char	**map)
{
	t_control	control;

	if (!map)
		free_map(s);
	control.is_the_door_accessible = 0;
	control.the_amount_of_coins_we_can_reach = 0;
	explore_map(map, &control, s->player_y, s->player_x);
	ft_malloc_error(map);
	if (!control.is_the_door_accessible)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nI can't reach the door\n");
		exit(1);
	}
	if (control.the_amount_of_coins_we_can_reach != s->count_c)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nWhole coins cannot collect\n");
		exit(1);
	}
}

void	map_control2(char *str, t_so_long *s)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp_tmp_map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile not opened!!!\n"), exit(1));
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nEmpty Map!!!\n"), close(fd), exit(1));
	s->map_width = ft_strlen(line);
	s->map_height = 1;
	tmp_map = ft_strdup("");
	while (line)
	{
		s->map_height++;
		tmp_tmp_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		tmp_map = tmp_tmp_map;
		line = get_next_line(fd);
	}
	close(fd);
	map_controls2(s, tmp_map);
}
