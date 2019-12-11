/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:50:26 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 15:43:10 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_sides(char *line, t_settings *settings)
{
	if (!ft_strncmp(line, "NO", 2))
		return (set_north_texture(settings, ++line));
	else if (!ft_strncmp(line, "SO", 2))
		return (set_south_texture(settings, ++line));
	else if (!ft_strncmp(line, "WE", 2))
		return (set_west_texture(settings, ++line));
	else if (!ft_strncmp(line, "EA", 2))
		return (set_east_texture(settings, ++line));
	return (0);
}

void		read_from_file(t_settings *settings)
{
	char	*line;
	int		result;
	int		read;
	char	*aux;

	result = 0;
	while ((read = get_next_line(settings->fd, &line)) > 0)
	{
		aux = line;
		while (*line == ' ')
			line++;
		if (*line == 'R')
			result += set_resolution(settings, line + 1);
		else if (*line == 'S')
			result += set_sprite(settings, ++line);
		else if (*line == 'F' || *line == 'C')
			result += set_floor_ceilling_color(settings, line);
		else
			result += check_sides(line, settings);
		free(aux);
		if (result == 8)
			return ;
	}
	error_handle(settings, "Wrong number of parameters");
}

void		check_file(int argc, char **argv, t_settings *settings)
{
	int		ch;

	if (argc != 2)
		error_handle(settings, "Usage: ./cub3D <file>");
	settings->fd = open(argv[1], O_RDONLY);
	if (settings->fd < 0)
		error_handle(settings, "<file> does not exist or is unreachable");
	ch = open(argv[1], O_DIRECTORY);
	if (ch > 0)
	{
		close(ch);
		error_handle(settings, "<file> is a directory");
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5))
		error_handle(settings, "<file> is not a .cub extension");
}
