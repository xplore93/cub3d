/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:06:38 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 20:22:36 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int argc, char **argv)
{
	t_settings	settings;

	init_settings(&settings);
	check_file(argc, argv, &settings);
	if (!(settings.mlx_ptr = mlx_init()))
		error_handle(&settings, "Could not initiate MLX");
	read_from_file(&settings);
	read_map(&settings);
	close(settings.fd);
	mlx_hook(settings.win_ptr, 17, 0, exit_program, &settings);
	tracing_handle(&settings);
	mlx_key_hook(settings.win_ptr, key_handle, &settings);
	mlx_loop(settings.mlx_ptr);
	return (0);
}
