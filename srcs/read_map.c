/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 09:50:22 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 18:00:52 by estina           ###   ########.fr       */
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

static int	map_size(t_settings *settings, char *line)
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
		error_handle(settings, "Wrong map format");
	return (size);
}

static void	handle_map(t_settings *settings, char *line, char **str)
{
	int		size;
	char	*tmp;
	char	*aux;

	size = map_size(settings, line);
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
		settings->map_cols = ft_strlen(*str) - 1;
	}
	free(aux);
}

void		read_map(t_settings *settings)
{
	char	*line;
	char	*aux;

	aux = NULL;
	while (get_next_line(settings->fd, &line) > 0)
	{
		if (ft_strlen(line))
		{
			handle_map(settings, line, &aux);
			settings->map_rows++;
		}
	}
	if (ft_strlen(line))
	{
		handle_map(settings, line, &aux);
		settings->map_rows++;
	}
	if (!(settings->map = ft_split(aux, '\n')))
		error_handle(settings, "Failed when splitting the map");
	free(aux);
	check_map(settings);
}
