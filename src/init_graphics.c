/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:42:41 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/26 07:48:32 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, game->cols * 60,
			game->rows * 60, "so_long");
	if (!game->win)
		return (1);
}

int	init_graphics(t_game *game)
{
	init_window(game);
	game->img_win_mess = mlx_xpm_file_to_image(game->mlx,
			"sprites/win_mess.xpm", &game->img_win_w, &game->img_win_h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"sprites/wall.xpm", &game->img_w, &game->img_h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/vader_right.xpm", &game->img_w, &game->img_h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/vader_left.xpm", &game->img_w, &game->img_h);
	game->img_player = game->img_player_right;
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"sprites/grogu.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"sprites/deathstar.xpm", &game->img_w, &game->img_h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"sprites/floor.xpm", &game->img_w, &game->img_h);
	if (!game->img_win_mess || !game->img_wall || !game->img_player_right
		|| !game->img_player_left || !game->img_collect || !game->img_exit
		|| !game->img_floor)
	{
		free_images(game);
		return (1);
	}
	return (0);
}
