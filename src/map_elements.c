/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:36:37 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/23 15:17:50 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_row_elements(t_game *game, t_counts *c, int row)
{
	int	j;

	j = 0;
	while (j < game->cols)
	{
		if (game->map[row][j] == 'E')
			c->exit_count++;
		else if (game->map[row][j] == 'P')
			c->player_count++;
		else if (game->map[row][j] == 'C')
			c->collect_count++;
		j++;
	}
}

void	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	game->collect_count = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'C')
				game->collect_count++;
			x++;
		}
		y++;
	}
}

int	is_valid_map_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (!ft_strchr("01CEP", game->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map_elements(t_game *game)
{
	t_counts	c;
	int			i;

	c.exit_count = 0;
	c.player_count = 0;
	c.collect_count = 0;
	i = 0;
	while (i < game->rows)
	{
		count_row_elements(game, &c, i);
		i++;
	}
	if (c.exit_count != 1 || c.player_count != 1 || c.collect_count < 1)
		return (0);
	return (1);
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
