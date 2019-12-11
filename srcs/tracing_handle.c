/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:20:16 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 20:23:54 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	tracing_handle(t_settings *set)
{
	int		i;
	double	x;
	double	angle;

	i = 0;
	while (i < set->map_cols)
	{
		x = i / set->resolution[X] - 0.5;
		angle = atan2(x, 0.66);
		i++;
	}
}
