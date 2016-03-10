/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:27:20 by alhote            #+#    #+#             */
/*   Updated: 2016/03/09 19:30:43 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int					draw_mandelbrot(void *arg)
{
	t_area	*a;
	int		pos[2];
	double	zoom[2];
	double	c[2];
	double	z[2];
	double	tmp[2];

	a = (t_area*)arg;
	zoom[0] = (a->f->sx / a->f->sd) / ((a->f->xf2 - a->f->xf1) / a->f->sd);
	zoom[1] = (a->f->sy / a->f->sd) / ((a->f->yf2 - a->f->yf1) / a->f->sd);
	pos[0] = 0;
	pos[1] = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	printf("%d\n", a->f->sx);
	while (pos[0] < (a->f->sx / a->f->sd))
	{
		while (pos[1] < (a->f->sy / a->f->sd))
		{
			printf("prout\n");
			c[0] = pos[0] / zoom[0] + a->f->xf1;
			c[1] = pos[1] / zoom[1] + a->f->yf1;
			z[0] = 0;
			z[1] = 0;
			tmp[1] = 0;
			while (z[0] * z[0] + z[1] * z[1] < 4 && tmp[1] < a->f->i_max)
			{
				printf("prout2\n");
				tmp[0] = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[1] * tmp[0] + c[1];
				++tmp[1];
			}
			if (tmp[1] == a->f->i_max)
				image_put_pixel(a->img, pos[0], pos[1], 0xFFFFFF);
			++pos[1];
		}
		pos[1] = 0;
		++pos[0];
	}
	//mlx_put_image_to_window(a->f->mlx, a->f->win, a->img, 0, 0);
	return (0);
}
