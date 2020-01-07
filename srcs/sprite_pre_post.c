/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_pre_post.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:57:34 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:46:24 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_sprite_3(t_cub3d *t, t_sprite *s, int tex_x, int stripe)
{
	int		y;
	int		tex_y;

	y = s->draw_s_y;
	while (y < s->draw_e_y)
	{
		if (s->text == 2 && t->life > 0)
			t->life -= 0.00001;
		tex_y = ((y * 2 - t->res[Y] + s->height) * t->sprite_tex[s->text].y)
			/ s->height * 0.5;
		t->color = (int)t->sprite_tex[s->text].data[tex_y *
			t->sprite_tex[s->text].sizeline + tex_x * 4];
		if (t->color)
			ft_memcpy(t->img_ptr + 4 * t->res[X] * y + stripe * 4,
				&t->sprite_tex[s->text].data[tex_y *
				t->sprite_tex[s->text].sizeline + tex_x * 4], sizeof(int));
		y++;
	}
}

static void	render_sprite_2(t_cub3d *t, t_sprite *s, double y_trans)
{
	int		stripe;
	int		tex_x;

	stripe = s->draw_s_x;
	while (stripe < s->draw_e_x)
	{
		tex_x = (int)(stripe - (-s->width / 2 + s->screen_x)) *
			t->sprite_tex[s->text].x / s->width;
		if (y_trans > 0 && stripe > 0 && stripe < t->res[X] && y_trans
			< t->z_buffer[stripe])
			render_sprite_3(t, s, tex_x, stripe);
		stripe++;
	}
}

static void	calc_pos(t_cub3d *t, t_sprite *s)
{
	s->sprite_x = s->x - t->x_raypos;
	s->sprite_y = s->y - t->y_raypos;
}

static void	check_draw(t_cub3d *t, t_sprite *s, double y_trans)
{
	int		vmove_screen;

	if (s->text == 2)
	{
		s->height = abs((int)(t->res[Y] / y_trans)) / 0.8;
		s->width = abs((int)(t->res[Y] / y_trans)) / 0.8;
	}
	vmove_screen = (int)(VMOVE / y_trans);
	if (s->text == 1)
		vmove_screen = (int)(2 / y_trans);
	s->draw_s_y = -s->height / 2 + t->res[Y] / 2 + vmove_screen;
	if (s->draw_s_y < 0)
		s->draw_s_y = 0;
	s->draw_e_y = s->height / 2 + t->res[Y] / 2 + vmove_screen;
	if (s->draw_e_y >= t->res[Y])
		s->draw_e_y = t->res[Y] - 1;
}

void		render_sprite(t_cub3d *t, t_sprite *s)
{
	double	inv;
	double	x_trans;
	double	y_trans;

	calc_pos(t, s);
	inv = 1.0 / (t->x_plane * t->y_dir - t->x_dir * t->y_plane);
	x_trans = inv * (t->y_dir * s->sprite_x - t->x_dir * s->sprite_y);
	y_trans = inv * (-t->y_plane * s->sprite_x + t->x_plane * s->sprite_y);
	s->screen_x = (int)((t->res[X] / 2) * (1 + x_trans / y_trans));
	s->height = abs((int)(t->res[Y] / y_trans)) / VDIV;
	s->width = abs((int)(t->res[Y] / y_trans)) / UDIV;
	check_draw(t, s, y_trans);
	if (s->text == 1)
	{
		s->height = abs((int)(t->res[Y] / y_trans)) / 2;
		s->width = abs((int)(t->res[Y] / y_trans)) * 2;
	}
	s->draw_s_x = -s->width / 2 + s->screen_x;
	if (s->draw_s_x < 0)
		s->draw_s_x = 0;
	s->draw_e_x = s->width / 2 + s->screen_x;
	render_sprite_2(t, s, y_trans);
}
