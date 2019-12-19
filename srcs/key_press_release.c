/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_release.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:55:35 by estina            #+#    #+#             */
/*   Updated: 2019/12/17 23:56:28 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
