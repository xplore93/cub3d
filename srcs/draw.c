/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:11:16 by estina            #+#    #+#             */
/*   Updated: 2019/12/24 11:17:01 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_floor(t_cub3d *t)
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

void		draw_floor(t_cub3d *t, int x, int start, int end)
{
	set_floor(t);
	while (++start < end)
	{
		t->curdist = t->res[Y] / (2.0 * start - t->res[Y]);
		t->weight = t->curdist / t->walldist;
		t->x_curfloortext = t->weight * t->x_floor + (1.0 - t->weight) *
			t->y_pos;
		t->y_curfloortext = t->weight * t->y_floor + (1.0 - t->weight) *
			t->x_pos;
		t->x_floortext = (int)(t->x_curfloortext * t->tex[t->id].x) %
			t->tex[t->id].x;
		t->y_floortext = (int)(t->y_curfloortext * t->tex[t->id].y) %
			t->tex[t->id].y;
		ft_memcpy(t->img_ptr + 4 * t->res[X] * start + 4 * x,
			&t->tex[t->id].data[4 * t->tex[t->id].x * t->x_floortext + 4 * t->y_floortext], sizeof(int));
	}
}

void		put_pxl_to_img(t_cub3d *t, int x, int y)
{
	t->y_text = fabs((((y * 2 - t->res[Y] + t->lineheight)
				* t->tex[t->id].y) / t->lineheight) * 0.5);
	ft_memcpy(t->img_ptr + 4 * t->res[X] * y + x * 4,
		&t->tex[t->id].data[t->y_text * t->tex[t->id].sizeline + t->x_text * 4],
		sizeof(int));
}

void		draw_wall(int x, int start, int end, t_cub3d *t)
{
	t->id = SO;
	if (t->side == 0)
		t->x_wall = t->y_raypos + t->walldist * t->y_raydir;
	else
	{
		t->id = WE;
		t->x_wall = t->x_raypos + t->walldist * t->x_raydir;
	}
	t->x_wall -= floor(t->x_wall);
	t->x_text = abs((int)(t->x_wall * (double)(t->tex[t->id].x)));
	if (t->side == 0 && t->x_raydir > 0)
		t->id = NO;
	if (t->side == 1 && t->y_raydir < 0)
		t->id = EA;
	while (++start <= end)
		put_pxl_to_img(t, x, start);
}

void		draw_sky(t_cub3d *t)
{
	t->x_text = 0;
	while (t->x_text < t->res[X])
	{
		t->y_text = 0;
		while (t->y_text < t->res[Y] / 2)
		{
			ft_memcpy(t->img_ptr + 4 * t->res[X] * t->y_text + t->x_text * 4,
					&t->tex[6].data[t->y_text % 512 * t->tex[6].sizeline +
					t->x_text % 512 * t->tex[6].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}
