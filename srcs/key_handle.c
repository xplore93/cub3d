/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:01:30 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 16:22:57 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_handle(int key, t_settings *settings)
{
	if (key == K_ESC)
		exit_program(settings);
	/*if (key == MLXK_A)
		state->pos = vector_add(state->pos, vector_scale(vector_rotate(state->dir, M_PI_2), MOVE_SPEED));
	if (key == MLXK_D)
		state->pos = vector_add(state->pos, vector_scale(vector_rotate(state->dir, -M_PI_2), MOVE_SPEED));
	if (key == MLXK_W)
		state->pos = vector_add(state->pos, vector_scale(state->dir, MOVE_SPEED));
	if (key == MLXK_S)
		state->pos = vector_add(state->pos, vector_scale(state->dir, -MOVE_SPEED));
	if (key == MLXK_LEFT)
		state->dir = vector_rotate(state->dir, -ROTATE_SIZE);
	if (key == MLXK_RIGHT)
		state->dir = vector_rotate(state->dir, ROTATE_SIZE);*/
	return (0);
}
