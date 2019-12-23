/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:33:01 by estina            #+#    #+#             */
/*   Updated: 2019/12/23 12:21:02 by estina           ###   ########.fr       */
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

static void	load_level(t_cub3d *t, int i)
{
	char	*adr;
	char	*aux;

	adr = t->level[0].addr;
	while(++i < 69)
	{
		aux = ft_strjoin(ft_itoa(i), ".xpm");
		t->level[i].addr = ft_strjoin(adr, aux);
		free(aux);
		check(t, t->level[i].addr);
		t->level[i].img = mlx_xpm_file_to_image(t->mlx, t->level[i].addr,
				&t->level[i].x, &t->level[i].y);
		t->level[i].data = mlx_get_data_addr(t->level[i].img, &t->level[i].bpp,
				&t->level[i].sizeline, &t->level[i].endian);
	}
	free(adr);
}

void		load_textures(t_cub3d *t)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		check(t, t->tex[i].addr);
		t->tex[i].img = mlx_xpm_file_to_image(t->mlx, t->tex[i].addr,
				&t->tex[i].x, &t->tex[i].y);
		t->tex[i].data = mlx_get_data_addr(t->tex[i].img, &t->tex[i].bpp,
				&t->tex[i].sizeline, &t->tex[i].endian);
	}
	load_level(t, -1);
	check(t, "textures/floor.xpm");
	t->tex[i].img = mlx_xpm_file_to_image(t->mlx, "textures/floor.xpm",
				&t->tex[i].x, &t->tex[i].y);
	t->tex[i].data = mlx_get_data_addr(t->tex[i].img, &t->tex[i].bpp,
			&t->tex[i].sizeline, &t->tex[i].endian);
	i++;
	check(t, "textures/sky.xpm");
	t->tex[i].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm",
				&t->tex[i].x, &t->tex[i].y);
	t->tex[i].data = mlx_get_data_addr(t->tex[i].img, &t->tex[i].bpp,
			&t->tex[i].sizeline, &t->tex[i].endian);
}
