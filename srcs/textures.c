/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:33:01 by estina            #+#    #+#             */
/*   Updated: 2019/12/13 17:46:27 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	load2(t_cub3d *t, int a, int b)
{
	a = 512;
	b = 512;
	t->tex[5].img = mlx_xpm_file_to_image(t->mlx, "textures/sky.xpm", &a, &b);
	t->tex[5].data = mlx_get_data_addr(t->tex[5].img, &t->tex[5].bpp,
			&t->tex[5].sizeline, &t->tex[5].endian);
}

void		load_textures(t_cub3d *t)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	t->tex[NO].img = mlx_xpm_file_to_image(t->mlx, t->tex[NO].addr + 2, &a, &b);
	t->tex[NO].data = mlx_get_data_addr(t->tex[NO].img, &t->tex[NO].bpp,
			&t->tex[NO].sizeline, &t->tex[NO].endian);
	t->tex[SO].img = mlx_xpm_file_to_image(t->mlx, t->tex[SO].addr + 2, &a, &b);
	t->tex[SO].data = mlx_get_data_addr(t->tex[SO].img, &t->tex[SO].bpp,
			&t->tex[SO].sizeline, &t->tex[SO].endian);
	t->tex[WE].img = mlx_xpm_file_to_image(t->mlx, t->tex[WE].addr + 2, &a, &b);
	t->tex[WE].data = mlx_get_data_addr(t->tex[WE].img, &t->tex[WE].bpp,
			&t->tex[WE].sizeline, &t->tex[WE].endian);
	t->tex[EA].img = mlx_xpm_file_to_image(t->mlx, t->tex[EA].addr + 2, &a, &b);
	t->tex[EA].data = mlx_get_data_addr(t->tex[EA].img, &t->tex[EA].bpp,
			&t->tex[EA].sizeline, &t->tex[EA].endian);
	t->tex[4].img = mlx_xpm_file_to_image(t->mlx, t->tex[4].addr + 2, &a, &b);
	t->tex[4].data = mlx_get_data_addr(t->tex[4].img, &t->tex[4].bpp,
			&t->tex[4].sizeline, &t->tex[4].endian);
	load2(t, a, b);
}
