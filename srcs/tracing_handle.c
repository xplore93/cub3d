/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:20:16 by estina            #+#    #+#             */
/*   Updated: 2019/12/18 12:30:50 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_init(t_cub3d *t)
{
	t->x_deltadist = fabs(1 / t->x_raydir);
	t->y_deltadist = fabs(1 / t->y_raydir);
	if (t->x_raydir < 0)
	{
		t->x_step = -1;
		t->x_sidedist = (t->x_raypos - t->x_map) * t->x_deltadist;
	}
	else
	{
		t->x_step = 1;
		t->x_sidedist = (t->x_map + 1.0 - t->x_raypos) * t->x_deltadist;
	}
	if (t->y_raydir < 0)
	{
		t->y_step = -1;
		t->y_sidedist = (t->y_raypos - t->y_map) * t->y_deltadist;
	}
	else
	{
		t->y_step = 1;
		t->y_sidedist = (t->y_map + 1.0 - t->y_raypos) * t->y_deltadist;
	}
}

void	dda(t_cub3d *t, char c)
{
	t->hit = 0;
	while (t->hit == 0)
	{
		if (t->x_sidedist < t->y_sidedist)
		{
			t->x_sidedist += t->x_deltadist;
			t->x_map += t->x_step;
			t->side = 0;
		}
		else
		{
			t->y_sidedist += t->y_deltadist;
			t->y_map += t->y_step;
			t->side = 1;
		}
		if (t->map[t->x_map][t->y_map] == c)
			t->hit = 1;
	}
}

void	ray_casting_init(t_cub3d *t, int x, char c)
{
	t->x_cam = 2 * x / (double)(t->res[X]) - 1;
	t->x_raypos = t->y_pos;
	t->y_raypos = t->x_pos;
	t->x_raydir = t->x_dir + t->x_plane * t->x_cam;
	t->y_raydir = t->y_dir + t->y_plane * t->x_cam;
	t->x_map = (int)t->x_raypos;
	t->y_map = (int)t->y_raypos;
	dda_init(t);
	dda(t, c);
	if (t->side == 0)
		t->walldist = (t->x_map - t->x_raypos +
				(1 - t->x_step) / 2) / t->x_raydir;
	else
		t->walldist = (t->y_map - t->y_raypos +
				(1 - t->y_step) / 2) / t->y_raydir;
}

void	tracing_handle(t_cub3d *t)
{
	t->x = -1;
	t->img = mlx_new_image(t->mlx, t->res[X], t->res[Y]);
	t->img_ptr = mlx_get_data_addr(t->img, &t->bpp, &t->sl, &t->endian);
	draw_sky(t);
	while (++t->x < t->res[X])
	{
		ray_casting_init(t, t->x, '1');
		t->lineheight = (int)(t->res[Y] / t->walldist);
		t->start = -t->lineheight / 2 + t->res[Y] / 2;
		if (t->start < 0)
			t->start = 0;
		t->end = t->lineheight / 2 + t->res[Y] / 2;
		if (t->end >= t->res[Y])
			t->end = t->res[Y] - 1;
		draw_wall(t->x, t->start - 1, t->end, t);
		sprite_handle(t, t->x, t->start - 1, t->end);
		floor_and_ceiling(t, t->x);
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_destroy_image(t->mlx, t->img);
}
