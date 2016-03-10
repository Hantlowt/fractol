/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:06:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/10 20:18:56 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						move_f(t_fractol *f, double x, double y, double z)
{
	while (f)
	{
		z = (double)z;
		f->xf1 += (x / f->i_max) + (z / f->i_max);
		f->xf2 += (x / f->i_max) - (z / f->i_max);
		f->yf1 += (y / f->i_max) + (z / f->i_max);
		f->yf2 += (y / f->i_max) - (z / f->i_max);
		f->i_max += (z / f->i_max) * 5;
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
	new->sx = sx;
	new->sy = sy;
	new->x = 0.0;
	new->y = 0.0;
	new->xf1 = -2.1;
	new->xf2 = 0.6;
	new->yf1 = -1.2;
	new->yf2 = 1.2;
	new->i_max = 50;
	new->img = mlx_new_image(mlx, sx, sy);
	new->next = NULL;
	return (new);
}
