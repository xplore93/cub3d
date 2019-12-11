/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:35:31 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 18:56:55 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_cols(t_settings *settings)
{
	int		i;

	i = 0;
	while (settings->map[i])
	{
		if ((int)ft_strlen(settings->map[i]) != settings->map_cols)
			error_handle(settings, "Wrong number of cols on map");
		i++;
	}
	if (i != settings->map_rows)
		error_handle(settings, "Wrong number of rows on map");
}

static void	check_walls(t_settings *settings)
{
	int		cols;
	int		rows;
	int		j;

	j = -1;
	cols = settings->map_cols;
	rows = settings->map_rows;
	while (++j < rows)
		if (settings->map[j][0] != '1' || settings->map[j][cols - 1] != '1')
			error_handle(settings, "There is no wall at left or right");
	j = -1;
	while (++j < cols)
		if (settings->map[0][j] != '1' || settings->map[rows - 1][j] != '1')
			error_handle(settings, "There is no wall at top or bottom");
}

static void	set_dir(t_settings *settings, int i, int j)
{
	char	c;

	c = *ft_strchr("NSEW", settings->map[i][j]);
	if (c == 'N')
		settings->player.dir_y = 1;
	else if (c == 'S')
		settings->player.dir_y = -1;
	else if (c == 'W')
		settings->player.dir_x = -1;
	else
		settings->player.dir_x = 1;
	settings->player.pos_x = j;
	settings->player.pos_y = i;
}

static void	check_values(t_settings *settings)
{
	int		i;
	int		j;
	int		found;

	i = -1;
	found = 0;
	while (++i < settings->map_rows)
	{
		j = -1;
		while (++j < settings->map_cols)
		{
			if (!ft_strchr("012NSEW", settings->map[i][j]))
				error_handle(settings, "Forbidden character on map");
			if (ft_strchr("NSEW", settings->map[i][j]))
			{
				if (found)
					error_handle(settings, "More than one position on map");
				found = 1;
				set_dir(settings, i, j);
			}
		}
	}
	if (!found)
		error_handle(settings, "There is no position on map");
}

void		check_map(t_settings *settings)
{
	check_cols(settings);
	check_walls(settings);
	check_values(settings);
}
