/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:36:37 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/20 08:15:59 by dhanlon          ###   ########.fr       */
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
