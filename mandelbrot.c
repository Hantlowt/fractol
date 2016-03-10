/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:27:20 by alhote            #+#    #+#             */
/*   Updated: 2016/03/10 19:11:33 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int					draw_mandelbrot(void *arg)
{
	t_fractol	*f;
	int		pos[2];
	double	zoom[2];
	double	c[2];
	double	z[2];
	double	tmp[2];

	f = (t_fractol*)arg;
	zoom[0] = f->sx / ((f->xf2 - f->xf1));
	zoom[1] = f->sy / ((f->yf2 - f->yf1));
	pos[0] = 0;
	pos[1] = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	while (pos[0] < f->sx)
	{
		while (pos[1] < f->sy)
		{
			c[0] = pos[0] / zoom[0] + f->xf1;
			c[1] = pos[1] / zoom[1] + f->yf1;
			z[0] = 0;
			z[1] = 0;
			tmp[1] = 0;
			while (z[0] * z[0] + z[1] * z[1] < 4 && tmp[1] < f->i_max)
			{
				tmp[0] = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[1] * tmp[0] + c[1];
				++tmp[1];
			}
			if (tmp[1] == f->i_max)
				image_put_pixel(f->img, pos[0], pos[1], 0);
			else
				image_put_pixel(f->img, f->x + pos[0], f->y + pos[1], (tmp[1] * 255) / f->i_max);
			++pos[1];
		}
		pos[1] = 0;
		++pos[0];
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
