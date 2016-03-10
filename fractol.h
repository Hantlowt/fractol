/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:07:47 by alhote            #+#    #+#             */
/*   Updated: 2016/03/09 19:22:18 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <mlx.h>

typedef struct			s_fractol
{
	void				*mlx;
	void				*win;
	int					sx;
	int					sy;
	double				xf1;//-2.1;
	double				xf2;//0.6;
	double				yf1;// = -1.2;
	double				yf2;// = 1.2;
	int					sd;
	int					i_max;
}						t_fractol;

typedef struct			s_area
{
	t_fractol			*f;
	int					id;
	void				*img;
}						t_area;

t_fractol				*init_f(void *mlx, int sx, int sy);
t_area					*init_a(t_fractol *f, int id);
int						move_f(t_fractol *f, double x, double y, double z);
int						draw_mandelbrot(void *arg);
void					image_put_pixel(void *img, int x, int y, int color);
#endif
