/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_read_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:50:26 by estina            #+#    #+#             */
/*   Updated: 2019/12/13 13:48:55 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	set_texture(t_cub3d *t, char *line, int i)
{
	while (*line && *line == ' ')
		line++;
	t->tex[i].addr = ft_strdup(line);
	return (1);
}

static int	check_sides(char *line, t_cub3d *t)
{
	if (!ft_strncmp(line, "NO", 2))
		return (set_texture(t, line + 2, 0));
	else if (!ft_strncmp(line, "SO", 2))
		return (set_texture(t, line + 2, 1));
	else if (!ft_strncmp(line, "WE", 2))
		return (set_texture(t, line + 2, 2));
	else if (!ft_strncmp(line, "EA", 2))
		return (set_texture(t, line + 2, 3));
	return (0);
}

void		read_from_file(t_cub3d *t)
{
	char	*line;
	int		result;
	int		read;
	char	*aux;

	result = 0;
	while ((read = get_next_line(t->fd, &line)) > 0)
	{
		aux = line;
		while (*line == ' ')
			line++;
		if (*line == 'R')
			result += set_resolution(t, line + 1);
		else if (!ft_strncmp(line, "S ", 2))
			result += set_sprite(t, ++line);
		else if (*line == 'F' || *line == 'C')
			result += set_floor_ceilling_color(t, line);
		else
			result += check_sides(line, t);
		free(aux);
		if (result == 8)
			return ;
	}
	error_handle(t, "Wrong number of parameters");
}

void		check_file(int argc, char **argv, t_cub3d *t)
{
	int		ch;

	if (argc != 2)
		error_handle(t, "Usage: ./cub3D <file>");
	t->fd = open(argv[1], O_RDONLY);
	if (t->fd < 0)
		error_handle(t, "<file> does not exist or is unreachable");
	ch = open(argv[1], O_DIRECTORY);
	if (ch > 0)
	{
		close(ch);
		error_handle(t, "<file> is a directory");
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5))
		error_handle(t, "<file> is not a .cub extension");
}
