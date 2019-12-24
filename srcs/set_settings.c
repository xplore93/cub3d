/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:46:26 by estina            #+#    #+#             */
/*   Updated: 2019/12/24 10:26:47 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_win_ptr(t_cub3d *t)
{
	int		x;
	int		y;

	if (t->res[X] > MAX_W)
		t->res[X] = MAX_W;
	if (t->res[Y] > MAX_H)
		t->res[Y] = MAX_H;
	x = t->res[X];
	y = t->res[Y];
	if (!(t->win = mlx_new_window(t->mlx, x, y, "cub3d")))
		error_handle(t, "Failed creating window");
}

int			set_sprite(t_cub3d *t, char *line)
{
	while (*line && *line == ' ')
		line++;
	t->level[0].addr = ft_strdup(line);
	return (1);
}

int			set_floor_ceilling_color(t_cub3d *t, char *line)
{
	int		i;

	i = 5;
	if (*line == 'F')
		i = 4;
	line++;
	while (*line && *line == ' ')
		line++;
	t->tex[i].addr = ft_strdup(line);
	return (1);
}

int			set_resolution(t_cub3d *t, char *line)
{
	while (*line && *line == ' ')
		line++;
	if (!(t->res[X] = ft_atoi(line)))
		return (0);
	line = ft_strrchr(line, ' ') + 1;
	if (!*line)
		error_handle(t, "There is no lines in the <file>");
	if (!(t->res[Y] = ft_atoi(line)))
		error_handle(t, "Wrong format of Resolution");
	set_win_ptr(t);
	return (1);
}
