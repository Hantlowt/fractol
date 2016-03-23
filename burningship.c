/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 19:51:47 by alhote            #+#    #+#             */
/*   Updated: 2016/03/23 17:14:38 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			draw_pixel_burningship(t_fractol *f)
{
	int		i;
	double	tmp;
	int		dv;

	i = 0;
	f->c_r = f->x / f->zoom_x + f->x1;
	f->c_i = f->y / f->zoom_y + f->y1;
	f->z_r = 0;
	f->z_i = 0;
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && i < f->i_max)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * fabs(f->z_i * tmp) + f->c_i;
		++i;
	}
	dv = 255 / f->i_max;
	if (i == f->i_max)
		img_pxl(f->img, f->x, f->y, ((i * dv) << (f->ecolor)) - 150);
	else
		img_pxl(f->img, f->x, f->y, (i * dv) << f->ecolor);
}

void				draw_burningship(t_fractol *f)
{
	int			x;
	int			y;

	x = f->x;
	y = f->y;
	f->zoom_x = f->sx / (f->x2 - f->x1);
	f->zoom_y = f->sy / (f->y2 - f->y1);
	while (f->x < f->msx)
	{
		while (f->y < f->msy)
		{
			draw_pixel_burningship(f);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	f->x = x;
	f->y = y;
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void				set_burningship(t_fractol *f)
{
	f->draw = draw_burningship;
}
