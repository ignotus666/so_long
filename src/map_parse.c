/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:22:33 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/20 19:18:55 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_error(t_parse *p)
{
	free(p->line);
	close(p->fd);
	return (1);
}

static int	check_line(t_parse *p, t_game *game)
{
	p->len = ft_strlen(p->line);
	if (p->len > 0 && p->line[p->len - 1] == '\n')
		p->len--;
	if (p->len == 0)
	{
		map_error("Empty line found\n");
		return (handle_error(p));
	}
	if (game->cols == -1)
		game->cols = p->len;
	else if (p->len != game->cols)
	{
		map_error("Non-rectangular line found\n");
		return (handle_error(p));
	}
	game->rows++;
	free(p->line);
	return (0);
}

int	parse_map(t_game *game)
{
	t_parse	p;

	p.fd = open(game->map_path, O_RDONLY);
	if (p.fd < 0)
		return (1);
	game->rows = 0;
	game->cols = -1;
	p.line = get_next_line(p.fd);
	while (p.line)
	{
		if (check_line(&p, game))
			return (1);
		p.line = get_next_line(p.fd);
	}
	close(p.fd);
	if (game->rows == 0)
		return (1);
	return (0);
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
