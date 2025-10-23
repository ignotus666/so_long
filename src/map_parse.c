/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:22:33 by dhanlon           #+#    #+#             */
/*   Updated: 2025/10/23 15:38:26 by dhanlon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	free_line(t_parse *p)
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
		return (free_line(p));
	}
	if (game->cols == -1)
		game->cols = p->len;
	else if (p->len != game->cols)
	{
		map_error("Non-rectangular line found\n");
		return (free_line(p));
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
		return (map_error("Could not open map file\n"));
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
		return (map_error("Map file empty\n"));
	return (0);
}

