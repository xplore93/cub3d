/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:35:31 by estina            #+#    #+#             */
/*   Updated: 2019/12/12 19:58:08 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_cols(t_cub3d *t)
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
}

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

static void	set_dir(t_cub3d *t, int i, int j)
{
	char	c;

	c = *ft_strchr("NSEW", t->map[i][j]);
	if (c == 'N')
		t->y_dir = 1;
	else if (c == 'S')
		t->y_dir = -1;
	else if (c == 'W')
		t->x_dir = -1;
	else
		t->x_dir = 1;
	t->x_pos = j;
	t->y_pos = i;
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
	if (!found)
		error_handle(t, "There is no position on map");
}

void		check_map(t_cub3d *t)
{
	check_cols(t);
	check_walls(t);
	check_values(t);
}
