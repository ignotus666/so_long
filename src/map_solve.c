/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 07:41:55 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/24 15:16:57 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= game->cols || y >= game->rows)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
}

static char	**copy_map(char **src, t_game *game)
{
	char	**dst;
	int		y;
	int		i;

	dst = malloc(sizeof(char *) * game->rows);
	if (!dst)
		return (NULL);
	y = 0;
	while (y < game->rows)
	{
		dst[y] = ft_strdup(src[y]);
		if (!dst[y])
		{
			i = 0;
			while (i < y)
				free(dst[i++]);
			free(dst);
			return (NULL);
		}
		y++;
	}
	return (dst);
}

static int	has_unreachable(char **map, char **visited, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if ((map[y][x] == 'C' || map[y][x] == 'E') && visited[y][x] != 'V')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_map_solvable(t_game *game)
{
	char	**map_cpy;
	int		i;
	int		solvable;

	map_cpy = copy_map(game->map, game);
	if (!map_cpy)
		return (0);
	flood_fill(map_cpy, game->player_x, game->player_y, game);
	solvable = !has_unreachable(game->map, map_cpy, game);
	i = 0;
	while (i < game->rows)
		free(map_cpy[i++]);
	free(map_cpy);
	return (solvable);
}
