/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:07:47 by alhote            #+#    #+#             */
/*   Updated: 2016/03/08 19:30:51 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>

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
	int					iteration_max;
}						t_fractol;

typedef struct			s_area
{
	s_fractol			*f;
	int					area_id;
}						t_area;

t_fractol				*init_f(void *mlx, void *win, int sx, int sy);
int						move_f(t_fractol *f, double x, double y, double z);
int						draw_mandelbrot(void *arg);
#endif
