/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:33:24 by estina            #+#    #+#             */
/*   Updated: 2020/01/06 18:12:00 by estina           ###   ########.fr       */
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
	t->life = t->res[X] / 5;
	t->life_full = t->life;
	t->reduce = t->res[Y] / 4;
}

static void	print_rect(t_cub3d *t, t_anchor anc, int color)
{
	int	h;
	int	w;
	int	*p;
	int	l;

	p = t->img_ptr;
	h = anc.y;
	l = t->res[X] * (int)(t->res[Y] / 1.2) + (int)(t->res[X] / 1.4);
	while (h < anc.y_goal)
	{
		w = anc.x;
		while (w < anc.x_goal)
		{
			p[l + h * t->res[X] + w] = color;
			w++;
		}
		h++;
	}
}

static void	render_player(t_cub3d *t)
{
	t_anchor anc;

	anc.x = t->x_pos * 0.15 * t->m_map.map;
	anc.y = t->y_pos * 0.15 * t->m_map.map;
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
			anc.x = col * t->m_map.map * 0.15;
			anc.y = row * t->m_map.map * 0.15;
			anc.y_goal = anc.y + t->m_map.map * 0.2;
			anc.x_goal = anc.x + t->m_map.map * 0.2;
			if (t->map[row][col] == '1')
				print_rect(t, anc, 125);
			else if (t->map[row][col] == '2')
				print_rect(t, anc, 16711680);
			else if (t->map[row][col] == '3')
				print_rect(t, anc, 1024);
			else
				print_rect(t, anc, 0x00FFFFFF);
		}
	}
	render_player(t);
}
