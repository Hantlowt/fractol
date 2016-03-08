/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:27:20 by alhote            #+#    #+#             */
/*   Updated: 2016/03/08 19:33:17 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						draw_mandelbrot(void *arg)
{
	t_area	*a;
	int		x;
	int		y;
	double	zoom_x;
	double	zoom_y;

	a = (t_area*)arg;
	zoom_x = (a->f->sx / a->f->sd) / (a->f->xf2 - a->f->xf1);
	zoom_y = (a->f->sy / a->f->sd) / (a->f->yf2 / a->f->sd - a->f->yf1);

	while (x < image_x)
	{
		while (y < image_y)
		{
			double c_r = x / zoom_x + x1;
			double c_i = y / zoom_y + y1;
			double z_r = 0;
			double z_i = 0;
			double i = 0;
			while (z_r*z_r + z_i*z_i < 4 && i < iteration_max)
			{
				double	tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}
			if (i == iteration_max)
				printf("draw");
			++y;
		}
		y = 0;
		++x;
	}
}
