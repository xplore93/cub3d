/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:01:30 by estina            #+#    #+#             */
/*   Updated: 2019/12/18 00:01:50 by estina           ###   ########.fr       */
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
	if (t->map[(int)(t->y_pos)]
		[(int)(t->x_pos + x * (ms + 0.2))] == '0')
		t->x_pos += x * ms;
	if (t->map[(int)(t->y_pos + y * (ms + 0.2))]
		[(int)(t->x_pos)] == '0')
		t->y_pos += y * ms;
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
	look_side(t);
	tracing_handle(t);
	return (0);
}