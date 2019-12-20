/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:22:14 by estina            #+#    #+#             */
/*   Updated: 2019/12/21 00:16:10 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	int_in_char(unsigned char *str, int value)
{
	int i;

	i = -1;
	while (++i < 4)
		str[i] = (unsigned char)(value >> (i * 8));
}

static int	write_header(t_cub3d *t, int fd, unsigned int fd_size)
{
	unsigned char	header[54];
	int				i;

	i = -1;
	while (++i < 54)
		header[i] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_in_char(header + 2, fd_size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_in_char(header + 18, t->res[X]);
	int_in_char(header + 22, -t->res[Y]);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (write(fd, header, 54));
}

static int	write_data(t_cub3d *t, int fd, unsigned int pad_byte_row)
{
	const unsigned char	zeroes[3] = {0, 0, 0};
	int					y;
	int					x;

	y = -1;
	while (++y < t->res[Y])
	{
		x = -1;
		while (++x < t->res[X])
			if (write(fd, &t->img_ptr[y * t->res[X] + x], 3) < 0)
				return (0);
		if (write(fd, &zeroes, pad_byte_row) < 0)
			return (0);
	}
	return (1);
}

void		screen_shot(t_cub3d *t)
{
	int				fd;
	unsigned int	fd_size;
	unsigned int	pxl_byte_row;
	unsigned int	pad_byte_row;

	tracing_handle(t);
	pxl_byte_row = t->res[X];
	pad_byte_row = (4 - (pxl_byte_row % 4)) % 4;
	fd_size = 54 + (pxl_byte_row + pad_byte_row) * t->res[Y];
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0777)) < 0)
		error_handle(t, "Couldn't create a screenshot");
	if (write_header(t, fd, fd_size) < 0)
		error_handle(t, "Can't write screenshot's header");
	if (!write_data(t, fd, pad_byte_row))
		error_handle(t, "Can't write screenshot's data");
	close(fd);
	exit_program(t);
}
