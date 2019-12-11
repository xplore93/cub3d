/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:22:27 by estina            #+#    #+#             */
/*   Updated: 2019/12/05 21:24:42 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_north_texture(t_settings *settings, char *line)	// TODO
{
	while (*line && *line == ' ')
		line++;
	settings->sides[NO] = ft_strdup(line);
	return (1);
}

int		set_south_texture(t_settings *settings, char *line)	// TODO
{
	while (*line && *line == ' ')
		line++;
	settings->sides[SO] = ft_strdup(line);
	return (1);
}

int		set_west_texture(t_settings *settings, char *line)	// TODO
{
	while (*line && *line == ' ')
		line++;
	settings->sides[WE] = ft_strdup(line);
	return (1);
}

int		set_east_texture(t_settings *settings, char *line)	// TODO
{
	while (*line && *line == ' ')
		line++;
	settings->sides[EA] = ft_strdup(line);
	return (1);
}
