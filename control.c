/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:33:24 by alhote            #+#    #+#             */
/*   Updated: 2016/03/23 18:10:30 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	f->draw(f);
	return (0);
}

int				mouse_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;

	f = (t_fractol*)param;
	x = x + 1;
	y = y + 1;
	if (button == 5)
		zoom_f(f, -0.05);
	if (button == 4)
		zoom_f(f, 0.05);
	f->draw(f);
	return (0);
}

int				mouse_motion(int x, int y, void *param)
{
	t_fractol	*f;

	f = (t_fractol*)param;
	f->c_r = (double)x / f->sx;
	f->c_i = (double)y / f->sy;
	f->draw(f);
	return (0);
}
