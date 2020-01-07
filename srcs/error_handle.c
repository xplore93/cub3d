/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:54:02 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:35:20 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		error_handle(t_cub3d *t, const char *s)
{
	int		i;

	ft_printf("Error\n");
	if (!s)
		perror("");
	else
		ft_printf("%s\n", s);
	i = -1;
	if (t->map)
	{
		while (++i < t->map_rows)
			free(t->map[i]);
		free(t->map);
	}
	if (t->fd > 0)
		close(t->fd);
	if (t->win)
		mlx_destroy_window(t->mlx, t->win);
	if (t->img)
		mlx_destroy_image(t->mlx, t->img);
	exit(1);
}

int			exit_program(t_cub3d *t)
{
	int			i;

	ft_printf("Closing the program...\n");
	i = -1;
	if (t->map)
	{
		while (++i < t->map_rows)
			free(t->map[i]);
		free(t->map);
	}
	if (t->fd > 0)
		close(t->fd);
	mlx_destroy_image(t->mlx, t->img);
	mlx_destroy_window(t->mlx, t->win);
	exit(0);
	return (0);
}

void		end_game(t_cub3d *t)
{
	ft_bzero(t->img_ptr, t->res[X] * t->res[Y] * 4);
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	mlx_string_put(t->mlx, t->win, (int)(t->res[X] / 2),
		(int)(t->res[Y] - t->res[Y] / 2), 0x00FF5555, "Game Over");
	mlx_string_put(t->mlx, t->win, (int)(t->res[X] / 2),
		(int)(t->res[Y] - t->res[Y] / 3), 0x00FFFFFF, "[ESC] to exit");
	mlx_string_put(t->mlx, t->win, (int)(t->res[X] / 2),
		(int)(t->res[Y] - t->res[Y] / 4), 0x00FFFFFF, "[SPACE] to restart");
}
