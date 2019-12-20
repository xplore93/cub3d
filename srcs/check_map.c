/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:35:31 by estina            #+#    #+#             */
/*   Updated: 2019/12/20 19:05:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_walls(t_cub3d *t)
{
	int		cols;
	int		rows;
	int		j;

	j = -1;
	cols = t->map_cols;
	rows = t->map_rows;
	while (++j < rows)
		if (t->map[j][0] != '1' || t->map[j][cols - 1] != '1')
			error_handle(t, "There is no wall at left or right");
	j = -1;
	while (++j < cols)
		if (t->map[0][j] != '1' || t->map[rows - 1][j] != '1')
			error_handle(t, "There is no wall at top or bottom");
}

static void	set_dir_ea_we(t_cub3d *t, char c)
{
	if (c == 'W')
	{
		t->x_dir = 0;
		t->y_dir = -1;
		t->x_plane = -0.66;
		t->y_plane = 0;
	}
	else
	{
		t->x_dir = 0;
		t->y_dir = 1;
		t->x_plane = 0.66;
		t->y_plane = 0;
	}
}

static void	set_dir(t_cub3d *t, int i, int j)
{
	char	c;

	c = *ft_strchr("NSEW", t->map[i][j]);
	if (c == 'N')
	{
		t->x_dir = -1;
		t->y_dir = 0;
		t->x_plane = 0;
		t->y_plane = 0.66;
	}
	else if (c == 'S')
	{
		t->x_dir = 1;
		t->y_dir = 0;
		t->x_plane = 0;
		t->y_plane = -0.66;
	}
	else
		set_dir_ea_we(t, c);
	t->x_pos = j + 0.5;
	t->y_pos = i + 0.5;
	t->map[i][j] = '0';
}

static void	check_values(t_cub3d *t)
{
	int		i;
	int		j;
	int		found;

	i = -1;
	found = 0;
	while (++i < t->map_rows)
	{
		j = -1;
		while (++j < t->map_cols)
		{
			if (t->map[i][j] == '2')
				init_sprite(t, i, j);
			if (!ft_strchr("012NSEW", t->map[i][j]))
				error_handle(t, "Forbidden character on map");
			if (ft_strchr("NSEW", t->map[i][j]))
			{
				if (found)
					error_handle(t, "More than one position on map");
				found = 1;
				set_dir(t, i, j);
			}
		}
	}
	return (found ? NULL : error_handle(t, "There is no position on map"));
}

void		check_map(t_cub3d *t)
{
	int		i;

	i = 0;
	while (t->map[i])
	{
		if ((int)ft_strlen(t->map[i]) != t->map_cols)
			error_handle(t, "Wrong number of cols on map");
		i++;
	}
	if (i != t->map_rows)
		error_handle(t, "Wrong number of rows on map");
	check_walls(t);
	check_values(t);
}
