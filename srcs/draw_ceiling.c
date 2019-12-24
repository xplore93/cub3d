/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:55:58 by estina            #+#    #+#             */
/*   Updated: 2019/12/24 11:25:44 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set(t_cub3d *t)
{
	if (t->side == 0 && t->x_raydir > 0)
	{
		t->x_floor = t->x_map;
		t->y_floor = t->y_map + t->x_wall;
	}
	else if (t->side == 0 && t->x_raydir < 0)
	{
		t->x_floor = t->x_map + 1.0;
		t->y_floor = t->y_map + t->x_wall;
	}
	else if (t->side == 1 && t->y_raydir > 0)
	{
		t->x_floor = t->x_map + t->x_wall;
		t->y_floor = t->y_map;
	}
	else
	{
		t->x_floor = t->x_map + t->x_wall;
		t->y_floor = t->y_map + 1.0;
	}
}

void		draw_ceiling(t_cub3d *t, int x, int start, int end)
{
	set(t);
	while (++start < end)
	{
		t->curdist = t->res[Y] / (2.0 * start - t->res[Y]);
		t->weight = t->curdist / t->walldist;
		t->x_curfloortext = t->weight * t->x_floor + (1.0 - t->weight) *
			t->y_pos;
		t->y_curfloortext = t->weight * t->y_floor + (1.0 - t->weight) *
			t->x_pos;
		t->x_floortext = (int)(t->x_curfloortext * t->tex[t->id].x * 0.25) %
			t->tex[t->id].x;
		t->y_floortext = (int)(t->y_curfloortext * t->tex[t->id].y * 0.25) %
			t->tex[t->id].y;
		if ((int)t->tex[t->id].data[4 * t->tex[t->id].x * t->x_floortext + 4 * t->y_floortext] != 0x00FFFFFF)
			ft_memcpy(t->img_ptr + 4 * t->res[X] * start + 4 * x,
				&t->tex[t->id].data[4 * t->tex[t->id].x * t->x_floortext + 4 * t->y_floortext], sizeof(int));
	}
}
