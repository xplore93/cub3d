/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:33:24 by estina            #+#    #+#             */
/*   Updated: 2019/12/19 17:12:47 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		set_mini_map(t_cub3d *t, t_mini_map *m_map)
{
	int	ratio_x;
	int ratio_y;
	int diff;

	ratio_x = t->res[X] / t->map_cols;
	ratio_y = t->res[Y] / t->map_rows;
	diff = ratio_x - ratio_y;
	m_map->map = ratio_y + (diff / 2);
	m_map->map += (m_map->map % 2) ? 1 : 0;
	m_map->player = m_map->map * 0.3;
	m_map->player = m_map->player < 10 ? 10 : m_map->player;
}

static void	print_rect(t_cub3d *t, t_anchor anc, int color)
{
	int	h;
	int	w;
	int	*p;

	p = t->img_ptr;
	h = anc.y;
	while (h < anc.y_goal)
	{
		w = anc.x;
		while (w < anc.x_goal)
		{
			p[h * t->res[X] + w] = color;
			w++;
		}
		h++;
	}
}

void		render_player(t_cub3d *t)
{
	t_anchor anc;

	anc.x = t->x_pos * 0.2 * t->m_map.map;
	anc.y = t->y_pos * 0.2 * t->m_map.map;
	anc.y_goal = anc.y + t->m_map.player * 0.5;
	anc.x_goal = anc.x + t->m_map.player * 0.5;
	print_rect(t, anc, 65280);
}

void		render_map(t_cub3d *t)
{
	int			row;
	int			col;
	t_anchor	anc;

	row = -1;
	while (++row < t->map_rows)
	{
		col = -1;
		while (++col < t->map_cols)
		{
			anc.x = col * t->m_map.map * 0.2;
			anc.y = row * t->m_map.map * 0.2;
			anc.y_goal = anc.y + t->m_map.map * 0.3;
			anc.x_goal = anc.x + t->m_map.map * 0.3;
			if (t->map[row][col] == '1')
				print_rect(t, anc, 0);
			else if (t->map[row][col] == '2')
				print_rect(t, anc, 16711680);
		}
	}
}
