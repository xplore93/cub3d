/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:33:01 by estina            #+#    #+#             */
/*   Updated: 2019/12/17 21:17:37 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check(t_cub3d *t, char *file)
{
	int		ch;
	int		fd;

	if (*file == '.')
		file += 2;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(t, "Texture does not exist or is unreachable");
	close(fd);
	ch = open(file, O_DIRECTORY);
	if (ch > 0)
	{
		close(ch);
		error_handle(t, "Texture is a directory");
	}
	if (ft_strncmp(ft_strrchr(file, '.'), ".xpm", 5))
		error_handle(t, "texture is not a .xpm extension");
}

void		load_textures(t_cub3d *t)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		check(t, t->tex[i].addr);
		t->tex[i].img = mlx_xpm_file_to_image(t->mlx, t->tex[i].addr,
				&t->tex[i].x, &t->tex[i].y);
		t->tex[i].data = mlx_get_data_addr(t->tex[i].img, &t->tex[i].bpp,
				&t->tex[i].sizeline, &t->tex[i].endian);
	}
	check(t, "textures/sky.xpm");
	t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm",
				&t->tex[i].x, &t->tex[i].y);
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
			&t->tex[5].sizeline, &t->tex[5].endian);
}
