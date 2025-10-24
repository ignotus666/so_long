/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:50:49 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/24 13:54:37 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flip_tile_to_player(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
}

static int	update_player_pos(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (new_x > game->player_x)
		game->player_dir = 0;
	else if (new_x < game->player_x)
		game->player_dir = 1;
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collect_count > 0)
			return (0);
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->move_count++;
		game->win_flag = 1;
		return (1);
	}
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collect_count--;
	}
	flip_tile_to_player(game, new_x, new_y);
	return (1);
}

static void	write_moves(t_game *game)
{
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1);
}

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	if (game->win_flag)
		return (0);
	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	if (update_player_pos(game, new_x, new_y))
		write_moves(game);
	draw_map(game);
	return (0);
}
