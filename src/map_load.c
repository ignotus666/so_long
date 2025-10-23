/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:40:42 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/23 20:52:55 by dhanlon          ###   ########.fr       */
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
		return (map_error("Could not load map into memory\n"));
	fd = open(game->map_path, O_RDONLY);
	if (fd < 0)
		return (map_error("Could not open map file\n"));
	i = 0;
	while (i < game->rows)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (map_error("Map file empty\n"));
		}
		game->map[i] = line;
		i++;
	}
	close(fd);
	return (0);
}
