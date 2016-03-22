/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:15:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/22 19:59:20 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

int				key(int keycode, void *param)
{
	t_fractol	*f;

	f = (t_fractol*)param;
	if (keycode == 124)
		move_f(f, 0.2, 0.0);
	if (keycode == 123)
		move_f(f, -0.2, 0.0);
	if (keycode == 126)
		move_f(f, 0.0, -0.2);
	if (keycode == 125)
		move_f(f, 0.0, 0.2);
	if (keycode == 16)
		zoom_f(f, 0.3);
	if (keycode == 4)
		zoom_f(f, -0.3);
	if (keycode == 15)
		f->ecolor = 16;
	if (keycode == 9)
		f->ecolor = 8;
	if (keycode == 11)
		f->ecolor = 0;
	if (keycode == 53)
		exit(0);
	//draw_julia(f);
	draw_burningship(f);
	return (0);
}

int				mouse_motion(int x, int y, void *param)
{
	t_fractol	*f;

	f = (t_fractol*)param;
	f->c_r = (double)x / f->sx;
	f->c_i = (double)y / f->sy;
	draw_julia(f);
	return (0);
}

int				main(void)
{
	t_fractol	*f;

	f = init_f(mlx_init(), 1920, 1080);
	f->win = mlx_new_window(f->mlx, 1920, 1080, "Fractol");
	mlx_hook(f->win, 2, (1L << 0), key, f);
	//mlx_hook(f->win, 6, (1L << 6), mouse_motion, f);
	/*f->x1 = -1.5;
	f->y1 = -1.5;
	f->x2 = 1.5;
	f->y2 = 1.5;
	f->i_max = 150;
	f->c_r = 0.285;
	f->c_i = 0.01;
	draw_julia(f);*/
	draw_burningship(f);
	mlx_loop(f->mlx);
	return (0);
}
