/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:46:26 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 20:23:02 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_win_ptr(t_settings *settings)
{
	int		x;
	int		y;

	if (settings->resolution[X] > MAX_W)
		settings->resolution[X] = MAX_W;
	if (settings->resolution[Y] > MAX_H)
		settings->resolution[Y] = MAX_H;
	x = settings->resolution[X];
	y = settings->resolution[Y];
	if (!(settings->win_ptr = mlx_new_window(settings->mlx_ptr, x, y, "cub3d")))
		error_handle(settings, "Failed creating window");
}

int			set_sprite(t_settings *settings, char *line)	// TODO
{
	while (*line && *line == ' ')
		line++;
	settings->sprite = ft_strdup(line);
	return (1);
}

int			set_floor_ceilling_color(t_settings *settings, char *line)
{
	char	**colors;
	int		*color;

	color = &settings->color[*line == 'F' ? X : Y];
	line = ft_strrchr(line, ' ') + 1;
	if (!(colors = ft_split(line, ',')))
		error_handle(settings, "Wrong format of colors");
	*color = (atoi(colors[0]) << 16) + (atoi(colors[1]) << 8) + atoi(colors[2]);
	return (1);
}

int			set_resolution(t_settings *settings, char *line)
{
	while (*line && *line == ' ')
		line++;
	if (!(settings->resolution[X] = ft_atoi(line)))
		return (0);
	line = ft_strrchr(line, ' ') + 1;
	if (!*line)
		error_handle(settings, "There is no lines in the <file>");
	if (!(settings->resolution[Y] = ft_atoi(line)))
		error_handle(settings, "Wrong format of Resolution");
	set_win_ptr(settings);
	return (1);
}
