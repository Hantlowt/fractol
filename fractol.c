/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:06:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/09 19:22:07 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_area					*init_a(t_fractol *f, int id)
{
	t_area	*new;

	if (!(new = (t_area*)malloc(sizeof(t_area))))
		return (0);
	new->f = f;
	new->id = id;
	new->img = mlx_new_image(new->f->mlx, new->f->sx / new->f->sd, new->f->sy / new->f->sd);
	return (new);
}

t_fractol				*init_f(void *mlx, int sx, int sy)
{
	t_fractol	*new;

	if (!(new = (t_fractol*)malloc(sizeof(t_fractol))))
		return (0);
	new->mlx = mlx;
	new->sx = sx;
	new->sy = sy;
	new->sd = 1;
	new->xf1 = -2.1;
	new->xf2 = 0.6;
	new->yf1 = -1.2;
	new->yf2 = 1.2;
	new->i_max = 50;
	return (new);
}
