/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:15:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/24 17:55:19 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			error(void)
{
	write(1, "usage: ./fractol 1|2|3|4 ", 25);
	write(1, "(Mandelbrot, Julia, Burningship or Tricorne)\n", 45);
	exit(0);
}

int				main(int argc, char *argv[])
{
	t_fractol	*f;

	if (argc == 2)
	{
		f = init_f(mlx_init(), 1920, 1080);
		f->win = mlx_new_window(f->mlx, 1920, 1080, "Fractol");
		mlx_hook(f->win, 2, (1L << 0), key, f);
		mlx_mouse_hook(f->win, mouse_hook, f);
		if (argv[1][0] == '1' && argv[1][1] == 0)
			set_mandelbrot(f);
		if (argv[1][0] == '2' && argv[1][1] == 0)
			set_julia(f);
		if (argv[1][0] == '3' && argv[1][1] == 0)
			set_burningship(f);
		if (argv[1][0] == '4' && argv[1][1] == 0)
			set_bonus(f);
		if (f->draw)
			f->draw(f);
		else
			error();
		mlx_loop(f->mlx);
	}
	else
		error();
	return (0);
}
