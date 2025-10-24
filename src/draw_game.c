/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:39:11 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/24 14:29:57 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, int x, int y)
{
	void	*img;

	img = game->img_floor;
	if (game->map[y][x] == '1')
		img = game->img_wall;
	else if (game->map[y][x] == 'P')
	{
		if (game->player_dir == 0)
			img = game->img_player_right;
		else
			img = game->img_player_left;
	}
	else if (game->map[y][x] == 'C')
		img = game->img_collect;
	else if (game->map[y][x] == 'E')
		img = game->img_exit;
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
	if (game->win_flag)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_win_mess,
			(game->cols * 32) / 2 - (game->img_win_w / 2),
			(game->rows * 32) / 2 - (game->img_win_h / 2));
}
