/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:06:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/17 17:23:13 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int						move_f(t_fractol *f, double x, double y)
{
	//x = (double)f->i_max;
	//y = (double)f->i_max;
	//z /= (double)f->i_max;
	while (f)
	{
		//f->six /= z;
		//f->siy /= z;
		f->x1 += (x);
		f->y1 += (y);
		f->x2 += (x);
		f->y2 += (y);
		//f->xf2 += (x / (scalex / 2)) + z / f->xf2;
		//f->yf2 += (y / (scaley / 2)) + z / f->yf2;
		//scale = ((f->xf2 - f->xf1) * (f->yf2 - f->yf1));
		//f->i_max += z * 2;
		f = f->next;
	}
	return (0);
}

t_fractol				*init_f(void *mlx, int sx, int sy)
{
	t_fractol	*new;

	if (!(new = (t_fractol*)malloc(sizeof(t_fractol))))
		return (0);
	new->mlx = mlx;
	new->scx = sx;
	new->scy = sy;
	new->six = sx;
	new->siy = sy;
	new->x1 = -2.1;
	new->x2 = 0.6;
	new->y1 = -1.2;
	new->y2 = 1.2;
	new->img = mlx_new_image(mlx, sx, sy);
	new->i_max = 50;
	new->next = NULL;
	return (new);
}
