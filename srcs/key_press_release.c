/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:55:35 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:20:52 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		restart(t_cub3d *t)
{
	t_sprite	*s;

	t->first = 1;
	t->bullets = 0;
	t->hudid = 0;
	t->enemies = 0;
	t->life = t->life_full;
	while (t->sprite)
	{
		s = t->sprite;
		t->sprite = t->sprite->next;
		free(s);
		t->num_sprite--;
	}
	free(t->sprite);
	check_file(t->args, t->file, t);
	read_from_file(t);
	read_map(t);
	close(t->fd);
	set_mini_map(t, &t->m_map);
}

int			key_press(int keycode, t_cub3d *t)
{
	if (keycode == K_W)
		t->move_up = 1;
	else if (keycode == K_S)
		t->move_down = 1;
	else if (keycode == K_R)
		t->look_right = 1;
	else if (keycode == K_L)
		t->look_left = 1;
	else if (keycode == K_D)
		t->move_right = 1;
	else if (keycode == K_A)
		t->move_left = 1;
	else if (keycode == 257)
		t->ms = 0.2;
	else if (keycode == 49 && t->life > 0)
		fire(t);
	else if (keycode == 49)
		restart(t);
	else if (keycode == K_ESC)
		exit_program(t);
	return (0);
}

int			key_release(int keycode, t_cub3d *t)
{
	if (keycode == K_W)
		t->move_up = 0;
	else if (keycode == K_S)
		t->move_down = 0;
	else if (keycode == K_R)
		t->look_right = 0;
	else if (keycode == K_L)
		t->look_left = 0;
	else if (keycode == K_D)
		t->move_right = 0;
	else if (keycode == K_A)
		t->move_left = 0;
	else if (keycode == 257)
		t->ms = 0.1;
	return (0);
}
