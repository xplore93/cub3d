/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 17:13:47 by estina            #+#    #+#             */
/*   Updated: 2020/01/07 13:19:57 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init_sprite(t_cub3d *t, int x, int y, int i)
{
	t_sprite	*sprite;

	t->num_sprite++;
	if (!(sprite = malloc(sizeof(*sprite))))
		error_handle(t, "Can't do malloc for sprites");
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
	if (t->sprite)
		sprite->next = t->sprite;
	else
		sprite->next = NULL;
	sprite->text = i;
	t->sprite = sprite;
}

void			init_sprites(t_cub3d *t, int i, int j)
{
	if (t->map[i][j] == '2')
		init_sprite(t, i, j, 0);
	if (t->map[i][j] == '3')
		init_sprite(t, i, j, 1);
	if (t->map[i][j] == '4')
	{
		init_sprite(t, i, j, 2);
		t->enemies++;
	}
}

void			sort_sprite(t_sprite **begin)
{
	t_sprite	*sp;
	t_sprite	*bef;
	t_sprite	*nxt;

	if (*begin)
	{
		sp = *begin;
		bef = 0;
		while (sp->next)
		{
			nxt = sp->next;
			if (sp->dist < nxt->dist)
			{
				sp->next = nxt->next;
				nxt->next = sp;
				if (bef)
					bef->next = nxt;
				else
					*begin = nxt;
				sp = *begin;
			}
			bef = sp;
			sp = sp->next;
		}
	}
}

void			generate_sprite(t_cub3d *t)
{
	t_sprite *beg;

	beg = t->sprite;
	while (beg)
	{
		beg->dist = (t->x_raypos - beg->x) * (t->x_raypos - beg->x)
			+ (t->y_raypos - beg->y) * (t->y_raypos - beg->y);
		beg = beg->next;
	}
	sort_sprite(&t->sprite);
	beg = t->sprite;
	while (t->sprite)
	{
		render_sprite(t, t->sprite);
		t->sprite = t->sprite->next;
	}
	t->sprite = beg;
}
