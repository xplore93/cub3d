/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_settings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:54:10 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 18:37:25 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_settings(t_settings *settings)
{
	settings->mlx_ptr = NULL;
	settings->win_ptr = NULL;
	settings->resolution[X] = 0;
	settings->resolution[Y] = 0;
	settings->sides[NO] = NULL;
	settings->sides[SO] = NULL;
	settings->sides[WE] = NULL;
	settings->sides[EA] = NULL;
	settings->sprite = NULL;
	settings->color[X] = 0;
	settings->color[Y] = 0;
	settings->map = NULL;
	settings->map_cols = 0;
	settings->map_rows = 0;
	settings->player.pos_x = 0;
	settings->player.pos_y = 0;
	settings->player.dir_x = 0;
	settings->player.dir_y = 0;
}
