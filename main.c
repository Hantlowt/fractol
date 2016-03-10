/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:15:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/09 19:22:36 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "fractol.h"

int				key(int keycode, void *param)
{
	t_fractol	*f;
	t_area		*a;

	a = (t_area*)param;
	f = a->f;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(f->mlx, f->win);
	draw_mandelbrot(a);
	printf("%d\n", keycode);
	return (0);
}

int				main(void)
{
	t_fractol	*f;
	t_area		*a;

	f = init_f(mlx_init(), 420, 420);
	f->win = mlx_new_window(f->mlx, f->sx, f->sy, "Fractol");
	a = init_a(f, 1);
	mlx_hook(f->win, 2, (1L << 0), key, f);
	mlx_loop(f->mlx);
	return (0);
}
