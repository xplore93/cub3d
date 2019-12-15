/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:03 by estina            #+#    #+#             */
/*   Updated: 2019/12/13 17:42:39 by estina           ###   ########.fr       */
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
# define K_L	123
# define K_R	124

typedef struct		s_tex
{
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*addr;
}					t_tex;

typedef struct		s_cub3d
{
	t_tex			tex[6];

	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;

	int				bpp;
	int				endian;
	int				sl;
	int				x_map;
	int				y_map;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				lineheight;
	int				start;
	int				end;
	int				move_up;
	int				move_down;
	int				move_left;
	int				move_right;
	int				x_text;
	int				y_text;
	int				id;
	int				texture;
	int				x_floortext;
	int				y_floortext;
	int				x;
	int				y;
	int				res[2];
	int				color[2];
	int				map_cols;
	int				map_rows;
	int				fd;

	char			**map;

	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_cam;
	double			x_raypos;
	double			y_raypos;
	double			x_raydir;
	double			y_raydir;
	double			x_sidedist;
	double			y_sidedist;
	double			x_deltadist;
	double			y_deltadist;
	double			walldist;
	double			x_olddir;
	double			x_oldplane;
	double			ms;
	double			rs;
	double			x_wall;
	double			x_floor;
	double			y_floor;
	double			x_curfloortext;
	double			y_curfloortext;
	double			curdist;
	double			weight;
}					t_cub3d;

void				error_handle(t_cub3d *t, const char *s);
int					exit_program(t_cub3d *t);
void				cub3d_init(t_cub3d *t);

void				check_file(int argc, char **argv, t_cub3d *t);
void				check_map(t_cub3d *t);
void				read_from_file(t_cub3d *t);
void				read_map(t_cub3d *t);

int					set_resolution(t_cub3d *t, char *line);
int					set_floor_ceilling_color(t_cub3d *t, char *line);
int					set_sprite(t_cub3d *t, char *line);

int					key_press(int keycode, t_cub3d *t);
int					key_release(int keycode, t_cub3d *t);
void				move_side(t_cub3d *t);
int					move(t_cub3d *t);
void				tracing_handle(t_cub3d *set);

void				floor_and_ceiling(t_cub3d *t, int x);
void				put_pxl_to_img(t_cub3d *t, int x, int y, int color);
void				draw_wall(int x, int start, int end, t_cub3d *t);
void				draw_sky(t_cub3d *t);
void				load_textures(t_cub3d *t);

#endif
