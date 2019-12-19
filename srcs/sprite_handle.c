/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 12:14:34 by estina            #+#    #+#             */
/*   Updated: 2019/12/18 12:31:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		sprite_handle(t_cub3d *t, int x, int start, int end)
{
	ray_casting_init(t, t->x, '2');
	
	while (++start <= end)
		put_pxl_to_img(t, x, start);
}
