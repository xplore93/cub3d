/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:11:16 by estina            #+#    #+#             */
/*   Updated: 2019/12/17 21:03:17 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_and_ceiling(t_cub3d *t, int x)
{
	if (t->end > 0)
	{
		t->y = t->end - 1;
		if (x < t->res[X] && t->y < t->res[Y])
			while (++t->y < t->res[Y])
				ft_memcpy(t->img_ptr + 4 * t->res[X] * t->y + x * 4,
						&t->color[X], sizeof(int));
	}
}

void	put_pxl_to_img(t_cub3d *t, int x, int y)
{
	t->y_text = abs((((y * 256 - t->res[Y] * 128 + t->lineheight * 128)
				* t->tex[t->id].y) / t->lineheight) / 256);
	ft_memcpy(t->img_ptr + 4 * t->res[X] * y + x * 4,
		&t->tex[t->id].data[t->y_text * t->tex[t->id].sizeline + t->x_text * 4],
		sizeof(int));
}

void	draw_wall(int x, int start, int end, t_cub3d *t)
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
	if (t->side == 0 && t->x_raydir > 0)
		t->id = NO;
	if (t->side == 1 && t->y_raydir < 0)
		t->id = EA;
	t->x_text = abs((int)(t->x_wall * (double)(t->tex[t->id].x)));
	while (++start <= end)
		put_pxl_to_img(t, x, start);
}

void	draw_sky(t_cub3d *t)
{
	t->x_text = 0;
	while (t->x_text < t->res[X])
	{
		t->y_text = 0;
		while (t->y_text < t->res[Y] / 2)
		{
			ft_memcpy(t->img_ptr + 4 * t->res[X] * t->y_text + t->x_text * 4,
					&t->tex[5].data[t->y_text % 512 * t->tex[5].sizeline +
					t->x_text % 512 * t->tex[5].bpp / 8], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}
