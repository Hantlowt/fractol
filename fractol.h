/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:07:47 by alhote            #+#    #+#             */
/*   Updated: 2016/03/14 15:21:21 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct			s_fractol
{
	void				*mlx;
	void				*win;
	int					scx;
	int					scy;
	double				x;
	double				y;
	double				six;
	double				siy;
	int					i_max;
	void				*img;
	struct s_fractol	*next;
}						t_fractol;

t_fractol				*init_f(void *mlx, int sx, int sy);
int						move_f(t_fractol *f, double x, double y, double z);
int						draw_mandelbrot(void *arg);
void					image_put_pixel(void *img, int x, int y, int color);
#endif
