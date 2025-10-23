/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:33:26 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/23 13:11:26 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_enclosed_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->cols)
	{
		if (game->map[game->rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (i < game->rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_error(const char *msg)
{
	write(1, "Error\n", 6);
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	validate_map(t_game *game)
{
	if (parse_map(game))
		return (1);
	if (load_map(game))
		return (1);
	if (!is_valid_map_chars(game))
		return (map_error("invalid character in map\n"));
	if (!is_enclosed_by_walls(game))
		return (map_error("walls check failed\n"));
	if (!check_map_elements(game))
		return (map_error("element check failed\n"));
	find_player_position(game);
	count_collectibles(game);
	if (!is_map_solvable(game))
		return (map_error("map is not solvable\n"));
	return (0);
}
