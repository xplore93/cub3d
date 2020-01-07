/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:50:22 by estina            #+#    #+#             */
/*   Updated: 2020/01/06 12:39:27 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*parse_line(char *line, int size)
{
	char	*aux;
	int		i;

	i = 0;
	aux = malloc(size + 2);
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
		{
			aux[i] = *line;
			i++;
			line++;
		}
	}
	aux[i] = '\n';
	aux[i + 1] = 0;
	return (aux);
}

static int	map_size(t_cub3d *t, char *line)
{
	int		size;

	size = 1;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
		{
			size++;
			line++;
		}
	}
	if (size == 1)
		error_handle(t, "Wrong map format");
	return (size);
}

static void	handle_map(t_cub3d *t, char *line, char **str)
{
	int		size;
	char	*tmp;
	char	*aux;

	size = map_size(t, line);
	aux = parse_line(line, size);
	if (*str)
	{
		tmp = *str;
		*str = ft_strjoin(*str, aux);
		free(tmp);
	}
	else
	{
		*str = ft_strdup(aux);
		t->map_cols = ft_strlen(*str) - 1;
	}
	free(aux);
}

void		read_map(t_cub3d *t)
{
	char	*line;
	char	*aux;

	aux = NULL;
	t->map_rows = 0;
	while (get_next_line(t->fd, &line) > 0)
	{
		if (ft_strlen(line))
		{
			handle_map(t, line, &aux);
			t->map_rows++;
		}
		free(line);
	}
	if (ft_strlen(line))
	{
		handle_map(t, line, &aux);
		t->map_rows++;
	}
	free(line);
	if (!(t->map = ft_split(aux, '\n')))
		error_handle(t, "Failed when splitting the map");
	free(aux);
	check_map(t);
}
