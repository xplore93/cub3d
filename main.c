/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:06:38 by estina            #+#    #+#             */
/*   Updated: 2019/12/23 11:34:29 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		cub3d_init(t_cub3d *t)
{
	t->win = NULL;
	t->map = NULL;
	t->sprite = NULL;
	t->x_dir = 0;
	t->y_dir = -1;
	t->x_plane = 0.3;
	t->y_plane = -0.1;
	t->ms = 0.1;
	t->rs = 0.1;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->look_left = 0;
	t->look_right = 0;
	t->x_text = 0;
	t->y_text = 0;
	t->num_sprite = 0;
	t->levid = 0;
}

int			main(int argc, char **argv)
{
	t_cub3d	t;

	cub3d_init(&t);
	check_file(argc, argv, &t);
	if (!(t.mlx = mlx_init()))
		error_handle(&t, "Could not initiate MLX");
	read_from_file(&t);
	load_textures(&t);
	read_map(&t);
	close(t.fd);
	set_mini_map(&t, &t.m_map);
	if (argc == 3 && (!ft_strncmp(argv[2], "--save", 7)))
	{
		screen_shot(&t);
		return (0);
	}
	mlx_hook(t.win, 17, 0, exit_program, &t);
	mlx_hook(t.win, 2, 0, key_press, &t);
	mlx_hook(t.win, 3, 0, key_release, &t);
	mlx_loop_hook(t.mlx, move, &t);
	mlx_loop(t.mlx);
	return (0);
}
