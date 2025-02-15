/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:01:30 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:32:17 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	look_side(t_cub3d *t)
{
	if (t->look_right)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(-t->rs) - t->y_dir * sin(-t->rs);
		t->y_dir = t->x_olddir * sin(-t->rs) + t->y_dir * cos(-t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-t->rs) - t->y_plane * sin(-t->rs);
		t->y_plane = t->x_oldplane * sin(-t->rs) + t->y_plane * cos(-t->rs);
	}
	if (t->look_left)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(t->rs) - t->y_dir * sin(t->rs);
		t->y_dir = t->x_olddir * sin(t->rs) + t->y_dir * cos(t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(t->rs) - t->y_plane * sin(t->rs);
		t->y_plane = t->x_oldplane * sin(t->rs) + t->y_plane * cos(t->rs);
	}
}

static void	movement(t_cub3d *t, double x, double y, int diag)
{
	double	ms;

	ms = t->ms;
	if (diag)
		ms /= sqrt(2);
	if (t->map[(int)(t->x_raypos)]
		[(int)(t->y_raypos + x * (ms + 0.2))] != '1'
			&& t->map[(int)(t->x_raypos)][(int)(t->y_raypos + x * (ms + 0.2))]
			!= '4')
		t->x_pos += x * ms;
	if (t->map[(int)(t->y_pos + y * (ms + 0.2))]
		[(int)(t->x_pos)] != '1' && t->map[(int)(t->y_pos + y * (ms + 0.2))]
		[(int)(t->x_pos)] != '4')
		t->y_pos += y * ms;
}

static void	dead_or_not(t_cub3d *t)
{
	if (t->life <= 0)
		end_game(t);
	else
	{
		look_side(t);
		tracing_handle(t);
		mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
		draw_text(t);
		if (t->enemies == 0)
		{
			t->file[1] = "maps/map1basic.cub";
			restart(t);
			load_textures(t);
		}
	}
}

int			move(t_cub3d *t)
{
	if (t->move_up && t->move_right)
		movement(t, t->y_dir - t->x_dir, t->x_dir + t->y_dir, 1);
	else if (t->move_up && t->move_left)
		movement(t, t->y_dir + t->x_dir, t->x_dir - t->y_dir, 1);
	else if (t->move_down && t->move_right)
		movement(t, -t->y_dir - t->x_dir, -t->x_dir + t->y_dir, 1);
	else if (t->move_down && t->move_left)
		movement(t, -t->y_dir + t->x_dir, -t->x_dir - t->y_dir, 1);
	else
	{
		if (t->move_up)
			movement(t, t->y_dir, t->x_dir, 0);
		if (t->move_down)
			movement(t, -t->y_dir, -t->x_dir, 0);
		if (t->move_right)
			movement(t, -t->x_dir, t->y_dir, 0);
		if (t->move_left)
			movement(t, t->x_dir, -t->y_dir, 0);
	}
	dead_or_not(t);
	return (0);
}
