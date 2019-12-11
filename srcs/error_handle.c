/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 07:54:02 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 18:08:00 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_handle(t_settings *settings, const char *s)
{
	int		i;

	ft_printf("Error\n");
	if (!s)
		perror("");
	else
		ft_printf("%s\n", s);
	i = -1;
	if (settings->map)
	{
		while (++i < settings->map_rows)
			free(settings->map[i]);
		free(settings->map);
	}
	if (settings->fd > 0)
		close(settings->fd);
	mlx_destroy_window(settings->mlx_ptr, settings->win_ptr);
	exit(1);
}

int		exit_program(t_settings *settings)
{
	int		i;

	ft_printf("Closing the program...\n");
	i = -1;
	if (settings->map)
	{
		while (++i < settings->map_rows)
			free(settings->map[i]);
		free(settings->map);
	}
	if (settings->fd > 0)
		close(settings->fd);
	mlx_destroy_window(settings->mlx_ptr, settings->win_ptr);
	exit(0);
	return (0);
}
