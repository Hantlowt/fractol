/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:04:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/23 17:40:45 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			draw_pixel_julia(t_fractol *f)
{
	int		i;
	double	tmp;
	int		dv;

	i = 0;
	f->z_r = f->x / f->zoom_x + f->x1;
	f->z_i = f->y / f->zoom_y + f->y1;
	while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && i < f->i_max)
	{
		tmp = f->z_r;
		f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * tmp + f->c_i;
		++i;
	}
	dv = 255 / f->i_max;
	if (i == f->i_max)
		img_pxl(f->img, f->x, f->y, ((i * dv) << (f->ecolor)) - 150);
	else
		img_pxl(f->img, f->x, f->y, (i * dv) << f->ecolor);
}

void				draw_julia(t_fractol *f)
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
			draw_pixel_julia(f);
			f->y++;
		}
		f->y = 0;
		f->x++;
	}
	f->x = x;
	f->y = y;
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void				set_julia(t_fractol *f)
{
	f->draw = draw_julia;
	f->x1 = -1.5;
	f->y1 = -1.5;
	f->x2 = 1.5;
	f->y2 = 1.5;
	f->i_max = 150;
	f->c_r = 0.285;
	f->c_i = 0.01;
	mlx_hook(f->win, 6, (1L << 6), mouse_motion, f);
}
