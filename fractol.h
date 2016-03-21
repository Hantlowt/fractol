/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 16:07:47 by alhote            #+#    #+#             */
/*   Updated: 2016/03/21 16:42:34 by alhote           ###   ########.fr       */
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
	int					sx;
	int					sy;
	int					msx;
	int					msy;
	double				zoom_x;
	double				zoom_y;
	int					x;
	int					y;
	int					px;
	int					py;
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	int					i_max;
	void				*img;
	struct s_fractol	*next;
}						t_fractol;

t_fractol				*init_f(void *mlx, int sx, int sy);
int						move_f(t_fractol *f, double x, double y);
int						draw_mandelbrot(void *arg);
int						zoom_f(t_fractol *f, double s);
void					img_pxl(void *img, int x, int y, int color);
int						rgbtoint(int r, int v, int b);
#endif
