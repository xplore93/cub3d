/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:01:30 by estina            #+#    #+#             */
/*   Updated: 2019/12/13 18:45:45 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_press(int keycode, t_cub3d *t)
{
	if (keycode == K_W)
		t->move_up = 1;
	else if (keycode == K_S)
		t->move_down = 1;
	else if (keycode == K_R)
		t->move_right = 1;
	else if (keycode == K_L)
		t->move_left = 1;
	else if (keycode == 257)
		t->ms = 0.10;
	else if (keycode == K_ESC)
		exit_program(t);
	return (0);
}

int		key_release(int keycode, t_cub3d *t)
{
	if (keycode == K_W)
		t->move_up = 0;
	else if (keycode == K_S)
		t->move_down = 0;
	else if (keycode == K_R)
		t->move_right = 0;
	else if (keycode == K_L)
		t->move_left = 0;
	else if (keycode == 257)
		t->ms = 0.05;
	return (0);
}

void	move_side(t_cub3d *t)
{
	if (t->move_right == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(-t->rs) - t->y_dir * sin(-t->rs);
		t->y_dir = t->x_olddir * sin(-t->rs) + t->y_dir * cos(-t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(-t->rs) - t->y_plane * sin(-t->rs);
		t->y_plane = t->x_oldplane * sin(-t->rs) + t->y_plane * cos(-t->rs);
	}
	if (t->move_left == 1)
	{
		t->x_olddir = t->x_dir;
		t->x_dir = t->x_dir * cos(t->rs) - t->y_dir * sin(t->rs);
		t->y_dir = t->x_olddir * sin(t->rs) + t->y_dir * cos(t->rs);
		t->x_oldplane = t->x_plane;
		t->x_plane = t->x_plane * cos(t->rs) - t->y_plane * sin(t->rs);
		t->y_plane = t->x_oldplane * sin(t->rs) + t->y_plane * cos(t->rs);
	}
}

int		move(t_cub3d *t)
{
	if (t->move_up == 1)
	{
		if (t->map[(int)(t->y_pos)]
			[(int)(t->x_pos + t->y_dir * t->ms + 0.1)] == '0')
			t->x_pos += t->y_dir * t->ms;
		if (t->map[(int)(t->y_pos + t->x_dir * t->ms  + 0.1)]
			[(int)(t->x_pos)] == '0')
			t->y_pos += t->x_dir * t->ms;
	}
	if (t->move_down == 1)
	{
		if (t->map[(int)(t->y_pos)]
			[(int)(t->x_pos - t->y_dir * t->ms + 0.1)] == '0')
			t->x_pos -= t->y_dir * t->ms;
		if (t->map[(int)(t->y_pos - t->x_dir * t->ms + 0.1)]
			[(int)(t->x_pos)] == '0')
			t->y_pos -= t->x_dir * t->ms;
	}
	move_side(t);
	tracing_handle(t);
	return (0);
}
