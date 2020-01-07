/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:26:08 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 12:30:15 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		draw_bar(t_cub3d *t)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = (int)(t->res[Y] - t->res[Y] / 8);
	t->color = 0x00005500;
	while (++i < t->life)
	{
		j = k;
		while (++j < k + 20)
			ft_memcpy(t->img_ptr + 4 * t->res[X] * j +
				(i + (int)(t->res[X] / 10)) * 4, &t->color, sizeof(int));
	}
	t->color = 0;
	while (++i < t->life_full)
	{
		j = k;
		while (++j < k + 20)
			ft_memcpy(t->img_ptr + 4 * t->res[X] * j +
				(i + (int)(t->res[X] / 10)) * 4, &t->color, sizeof(int));
	}
}

void		draw_cross(t_cub3d *t)
{
	int		x;
	int		y;
	int		x_e;
	int		y_e;

	x = (t->res[X] / 2) - t->res[X] / 80 - 1;
	x_e = (t->res[X] / 2) + t->res[X] / 80;
	y_e = (t->res[Y] / 2) + t->res[Y] / 40;
	t->color = 0x00FFFFFF;
	while (++x < x_e)
	{
		y = (t->res[Y] / 2) - t->res[Y] / 40 - 1;
		while (++y < y_e)
		{
			if (((x < t->res[X] / 2) && (y > ((t->res[Y] / 2) - 2) &&
				y < ((t->res[Y] / 2) + 2)))
				|| (x > ((t->res[X] / 2) - 2) && x < ((t->res[X] / 2) + 2))
				|| (x > t->res[X] / 2 && (y > ((t->res[Y] / 2) - 2)
				&& y < ((t->res[Y] / 2) + 2))))
				ft_memcpy(t->img_ptr + 4 * t->res[X] * y + x * 4, &t->color,
				sizeof(int));
		}
	}
}
