/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:23:41 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/22 10:46:04 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid_map_arg(int argc, char **argv, t_game *game)
{
	int			len;

	if (argc != 2)
		return (map_error("Wrong number of arguments\n"));
	len = ft_strlen(game->map_path);
	if (len < 5 || ft_strncmp(game->map_path + len - 4, ".ber", 4) != 0)
		return (map_error("Error: the map file must have a .ber extension\n"));
	return (0);
}

int	expose_hook(t_game *game)
{
	draw_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	game.map_path = argv[1];
	if (is_valid_map_arg(argc, argv, &game))
		return (1);
	if (validate_map(&game))
		return (1);
	if (init_graphics(&game))
		return (1);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 12, 1L << 15, expose_hook, &game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	game.player_dir = 0;
	game.win_flag = 0;
	game.move_count = 0;
	draw_map(&game);
	mlx_loop(game.mlx);
	free_map(&game);
	return (0);
}
