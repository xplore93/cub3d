/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:14:22 by estina            #+#    #+#             */
/*   Updated: 2020/01/06 18:57:59 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		draw_text(t_cub3d *t)
{
	char	*str;
	char	*aux;

	aux = ft_itoa((int)(100 * t->life / t->life_full));
	str = ft_strjoin(aux, " / 100");
	mlx_string_put(t->mlx, t->win, (int)(t->res[X] / 5),
		(int)(t->res[Y] - t->res[Y] / 9), 0x00FFFFFF, str);
	free(str);
	str = ft_itoa(t->bullets);
	mlx_string_put(t->mlx, t->win, (int)(t->res[X] / 2 - 10),
		(int)(t->res[Y] - t->res[Y] / 20), 0x00FFFFFF, str);
	free(aux);
	free(str);
}
