/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:03 by estina            #+#    #+#             */
/*   Updated: 2019/12/11 19:59:52 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# define MAX_W	2560
# define MAX_H	1395
# define X		0
# define Y		1
# define NO		0
# define SO		1
# define WE		2
# define EA		3
# define K_ESC	53
# define K_W	13
# define K_D	2
# define K_S	1
# define K_A	0

typedef struct		s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
}					t_player;

typedef struct		s_settings
{
	void			*mlx_ptr;
	void			*win_ptr;

	int				resolution[2];
	void			*sides[4];
	void			*sprite;
	int				color[2];
	char			**map;

	int				map_cols;
	int				map_rows;

	t_player		player;

	int				fd;

}					t_settings;

void				init_settings(t_settings *settings);
void				error_handle(t_settings *settings, const char *s);
int					exit_program(t_settings *settings);

void				check_file(int argc, char **argv, t_settings *settings);
void				check_map(t_settings *settings);
void				read_from_file(t_settings *settings);
void				read_map(t_settings *settings);

int					set_resolution(t_settings *settings, char *line);
int					set_floor_ceilling_color(t_settings *settings, char *line);
int					set_sprite(t_settings *settings, char *line);

int					set_north_texture(t_settings *settings, char *line);
int					set_south_texture(t_settings *settings, char *line);
int					set_west_texture(t_settings *settings, char *line);
int					set_east_texture(t_settings *settings, char *line);

int					key_handle(int key, t_settings *settings);
void				tracing_handle(t_settings *set);

#endif
