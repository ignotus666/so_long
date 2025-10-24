/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:25:13 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/24 13:59:45 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_UP		65362
# define KEY_DOWN	65364
# define KEY_LEFT	65361
# define KEY_RIGHT	65363

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	const char	*map_path;
	int			rows;
	int			cols;
	int			player_x;
	int			player_y;
	int			player_dir;
	void		*img_wall;
	void		*img_player;
	void		*img_player_right;
	void		*img_player_left;
	void		*img_collect;
	void		*img_exit;
	void		*img_floor;
	void		*img_win_mess;
	int			img_w;
	int			img_h;
	int			img_win_w;
	int			img_win_h;
	int			win_flag;
	int			collect_count;
	int			move_count;
}	t_game;

typedef struct s_parse
{
	int		fd;
	char	*line;
	int		len;
}	t_parse;

typedef struct s_counts
{
	int	exit_count;
	int	player_count;
	int	collect_count;
}	t_counts;

int		init_graphics(t_game *game);
int		check_map_elements(t_game *game);
int		validate_map(t_game *game);
int		is_valid_map_chars(t_game *game);
int		is_map_solvable(t_game *game);
int		parse_map(t_game *game);
int		load_map(t_game *game);
void	free_map(t_game *game);
void	free_images(t_game *game);
void	draw_map(t_game *game);
int		key_hook(int keycode, t_game *game);
void	find_player_position(t_game *game);
int		close_window(t_game *game);
void	count_collectibles(t_game *game);
int		expose_hook(t_game *game);
int		map_error(const char *msg);

#endif