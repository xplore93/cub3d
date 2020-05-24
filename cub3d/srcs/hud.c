/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:23:23 by estina            #+#    #+#             */
/*   Updated: 2020/01/06 19:00:26 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		load_hud(t_cub3d *t)
{
	t->hud[0].addr = "textures/hud/hud0.xpm";
	t->hud[1].addr = "textures/hud/hud1.xpm";
	check(t, t->hud[0].addr);
	check(t, t->hud[1].addr);
	t->hud[0].img = mlx_xpm_file_to_image(t->mlx, t->hud[0].addr,
		&t->hud[0].x, &t->hud[0].y);
	t->hud[0].data = mlx_get_data_addr(t->hud[0].img, &t->hud[0].bpp,
		&t->hud[0].sizeline, &t->hud[0].endian);
	t->hud[1].img = mlx_xpm_file_to_image(t->mlx, t->hud[1].addr,
		&t->hud[1].x, &t->hud[1].y);
	t->hud[1].data = mlx_get_data_addr(t->hud[1].img, &t->hud[1].bpp,
		&t->hud[1].sizeline, &t->hud[1].endian);
}

static void	change_weapon(t_cub3d *t)
{
	t_sprite	*aux;
	t_sprite	*ant;

	t->hudid = 1;
	aux = t->sprite;
	ant = NULL;
	while (aux)
	{
		if ((int)aux->x == (int)t->y_pos && (int)aux->y == (int)t->x_pos
			&& aux->text == 1)
		{
			if (ant)
				ant->next = aux->next;
			else
				t->sprite = t->sprite->next;
			free(aux);
			t->num_sprite--;
			t->map[(int)t->y_pos][(int)t->x_pos] = '0';
			t->bullets += 20;
			break ;
		}
		ant = aux;
		aux = aux->next;
	}
}

static void	restore_life(t_cub3d *t)
{
	t_sprite	*aux;
	t_sprite	*ant;

	aux = t->sprite;
	ant = NULL;
	while (aux)
	{
		if ((int)aux->x == (int)t->y_pos && (int)aux->y == (int)t->x_pos
			&& aux->text == 0)
		{
			if (ant)
				ant->next = aux->next;
			else
				t->sprite = t->sprite->next;
			free(aux);
			t->num_sprite--;
			t->life += t->life_full / 5;
			if (t->life > t->life_full)
				t->life = t->life_full;
			t->map[(int)t->y_pos][(int)t->x_pos] = '0';
			break ;
		}
		ant = aux;
		aux = aux->next;
	}
}

void		draw_hud(t_cub3d *t)
{
	int		tex[2];

	t->res[Y] += t->reduce;
	if (t->map[(int)t->y_pos][(int)t->x_pos] == '3')
		change_weapon(t);
	if (t->map[(int)t->y_pos][(int)t->x_pos] == '2')
		restore_life(t);
	t->x_text = 0;
	while (t->x_text < t->res[X])
	{
		t->y_text = 0;
		tex[X] = t->x_text * t->hud[t->hudid].x / t->res[X];
		while (t->y_text < t->res[Y])
		{
			tex[Y] = t->y_text * t->hud[t->hudid].y / t->res[Y];
			t->color = (int)t->hud[t->hudid].data[tex[Y] *
				t->hud[t->hudid].sizeline + tex[X] * 4];
			if (t->color)
				ft_memcpy(t->img_ptr + 4 * t->y_text * t->res[X] + t->x_text
					* 4, &t->hud[t->hudid].data[t->hud[t->hudid].sizeline *
					tex[Y] + tex[X] * 4], sizeof(int));
			t->y_text++;
		}
		t->x_text++;
	}
}
