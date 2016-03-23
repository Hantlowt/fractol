/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:06:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/23 18:08:30 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						move_f(t_fractol *f, double x, double y)
{
	double	d[2];

	d[0] = (f->x2 - f->x1);
	d[1] = (f->y2 - f->y1);
	if (x > 0)
	{
		f->x1 += d[0] * x;
		f->x2 = f->x1 + d[0];
	}
	else
	{
		f->x1 -= d[0] * -x;
		f->x2 = f->x1 + d[0];
	}
	if (y > 0)
	{
		f->y1 += d[1] * y;
		f->y2 = f->y1 + d[1];
	}
	else
	{
		f->y1 -= d[1] * -y;
		f->y2 = f->y1 + d[1];
	}
	return (0);
}

int						zoom_f(t_fractol *f, double s)
{
	double	d[2];

	d[0] = (f->x2 - f->x1);
	d[1] = (f->y2 - f->y1);
	if (s > 0)
	{
		f->x1 += (f->x2 - f->x1) * s;
		f->y1 += (f->y2 - f->y1) * s;
		f->x2 -= (f->x2 - f->x1) * s;
		f->y2 -= (f->y2 - f->y1) * s;
		f->i_max += (int)s * 90;
	}
	else
	{
		f->x1 -= (f->x2 - f->x1) * -s;
		f->y1 -= (f->y2 - f->y1) * -s;
		f->x2 += (f->x2 - f->x1) * -s;
		f->y2 += (f->y2 - f->y1) * -s;
		f->i_max -= (int)s * 90;
	}
	f->i_max = (f->i_max < 50 ? 50 : f->i_max);
	return (0);
}

t_fractol				*init_f(void *mlx, int sx, int sy)
{
	t_fractol	*new;

	if (!(new = (t_fractol*)malloc(sizeof(t_fractol))))
		return (0);
	new->mlx = mlx;
	new->x = 0;
	new->y = 0;
	new->msx = sx;
	new->msy = sy;
	new->sx = sx;
	new->sy = sy;
	new->x1 = -2.1;
	new->x2 = 0.6;
	new->y1 = -1.2;
	new->y2 = 1.2;
	new->img = mlx_new_image(mlx, sx, sy);
	new->i_max = 90;
	new->ecolor = 0;
	new->draw = 0;
	return (new);
}
