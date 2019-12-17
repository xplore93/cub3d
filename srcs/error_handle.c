/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:54:02 by estina            #+#    #+#             */
/*   Updated: 2019/12/17 19:39:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_handle(t_cub3d *t, const char *s)
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
	exit(1);
}

int		exit_program(t_cub3d *t)
{
	int		i;

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
	mlx_destroy_window(t->mlx, t->win);
	exit(0);
	return (0);
}
