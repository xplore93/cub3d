/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:22:14 by estina            #+#    #+#             */
/*   Updated: 2019/12/24 09:29:39 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int		write_bmp_header(int fd, int filesize, t_cub3d *t)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	set_int_in_char(bmpfileheader + 18, t->res[X]);
	set_int_in_char(bmpfileheader + 22, t->res[Y]);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int		get_color(t_cub3d *t, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(t->img_ptr
			+ (4 * t->res[X] * (t->res[Y] - 1 - y))
			+ (4 * x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int		write_bmp_data(int file, t_cub3d *t, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < (int)t->res[Y])
	{
		j = 0;
		while (j < (int)t->res[X])
		{
			color = get_color(t, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				save_bmp(t_cub3d *t)
{
	int			filesize;
	int			file;
	int			pad;

	tracing_handle(t);
	pad = (4 - (t->res[X] * 3) % 4) % 4;
	filesize = 54 + (3 * (t->res[X] + pad) * t->res[Y]);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND)) < 0)
		return (0);
	if (!write_bmp_header(file, filesize, t))
		return (0);
	if (!write_bmp_data(file, t, pad))
		return (0);
	close(file);
	exit_program(t);
	return (1);
}
