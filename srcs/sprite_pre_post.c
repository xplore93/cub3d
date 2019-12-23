/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_pre_post.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:57:34 by estina            #+#    #+#             */
/*   Updated: 2019/12/23 11:43:00 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_sprite_3(t_cub3d *t, t_sprite *s, int tex_x, int stripe)
{
	int		y;
	int		d;
	int		tex_y;
	int		color;

	y = s->draw_s_y;
	while (y < s->draw_e_y)
	{
		d = y * 256 - t->res[Y] * 128 + s->height * 128;
		tex_y = (d * t->level[t->levid].y) / s->height / 256;
		color = (int)t->level[t->levid].data[tex_y *
			t->level[t->levid].sizeline + tex_x * 4];
		if ((color & 0x00FFFFFF) != 0)
			ft_memcpy(t->img_ptr + 4 * t->res[X] * y + stripe * 4,
				&t->level[t->levid].data[tex_y * t->level[t->levid].sizeline +
				tex_x * 4], sizeof(int));
		y++;
	}
}

static void	render_sprite_2(t_cub3d *t, t_sprite *s, double y_trans)
{
	int		stripe;
	int		tex_x;

	stripe = s->draw_s_x;
	if (t->levid > 67)
		t->levid = 0;
	else
		t->levid++;
	while (stripe < s->draw_e_x)
	{
		tex_x = (int)(256 * (stripe - (-s->width / 2 + s->screen_x))
			* t->level[t->levid].x / s->width) / 256;
		if (y_trans > 0 && stripe > 0 && stripe < t->res[X] && y_trans
			< t->z_buffer[stripe])
			render_sprite_3(t, s, tex_x, stripe);
		stripe++;
	}
}

void		render_sprite(t_cub3d *t, t_sprite *s)
{
	double	inv;
	double	x_trans;
	double	y_trans;

	s->sprite_x = s->x - t->x_raypos;
	s->sprite_y = s->y - t->y_raypos;
	inv = 1.0 / (t->x_plane * t->y_dir - t->x_dir * t->y_plane);
	x_trans = inv * (t->y_dir * s->sprite_x - t->x_dir * s->sprite_y);
	y_trans = inv * (-t->y_plane * s->sprite_x + t->x_plane * s->sprite_y);
	s->screen_x = (int)((t->res[X] / 2) * (1 + x_trans / y_trans));
	s->height = abs((int)(t->res[Y] / y_trans)) / 2;
	s->draw_s_y = -s->height / 2 + t->res[Y] / 2;
	if (s->draw_s_y < 0)
		s->draw_s_y = 0;
	s->draw_e_y = s->height / 2 + t->res[Y] / 2;
	if (s->draw_e_y >= t->res[Y])
		s->draw_e_y = t->res[Y] - 1;
	s->width = abs((int)(t->res[Y] / y_trans));
	s->draw_s_x = -s->width / 2 + s->screen_x;
	if (s->draw_s_x < 0)
		s->draw_s_x = 0;
	s->draw_e_x = s->width / 2 + s->screen_x;
	if (s->draw_e_y >= t->res[X])
		s->draw_e_y = t->res[X] - 1;
	render_sprite_2(t, s, y_trans);
}
