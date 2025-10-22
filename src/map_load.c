/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:40:42 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/20 08:12:00 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	game->map = malloc(sizeof(char *) * game->rows);
	if (!game->map)
		return (1);
	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (i < game->rows)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (1);
		}
		game->map[i] = line;
		i++;
	}
	close(fd);
	return (0);
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
