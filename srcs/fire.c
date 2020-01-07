/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:03:16 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:48:08 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		kill_enemy(t_cub3d *t)
{
	t_sprite	*aux;
	t_sprite	*ant;

	aux = t->sprite;
	ant = NULL;
	while (aux)
	{
		if ((int)aux->x == t->x_map && (int)aux->y == t->y_map
			&& aux->text == 2)
		{
			t->map[(int)aux->x][(int)aux->y] = '0';
			if (ant)
				ant->next = aux->next;
			else
				t->sprite = t->sprite->next;
			free(aux);
			t->num_sprite--;
			t->enemies--;
			break ;
		}
		ant = aux;
		aux = aux->next;
	}
}

void		fire(t_cub3d *t)
{
	if (--t->bullets > 0)
		t->fire = 1;
	else
	{
		t->hudid = 0;
		t->bullets = 0;
	}
}
