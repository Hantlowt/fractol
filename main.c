/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:15:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/21 21:17:52 by alhote           ###   ########.fr       */
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
	if (keycode == 46)
		f->ecolor += 1;
	if (keycode == 45)
		f->icolor += 1;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(f->mlx, f->win);
	draw_mandelbrot(f);
	printf("%d\n", keycode);
	return (0);
}

int				main(void)
{
	t_fractol	*f;

	f = init_f(mlx_init(), 1920, 1080);
	f->win = mlx_new_window(f->mlx, 1920, 1080, "Fractol");
	mlx_hook(f->win, 2, (1L << 0), key, f);
	draw_mandelbrot(f);
	mlx_loop(f->mlx);
	return (0);
}
