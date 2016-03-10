/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 19:06:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/10 15:45:32 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol				*init_f(void *mlx, int sx, int sy, int sd)
{
	t_fractol	*new;

	if (!(new = (t_fractol*)malloc(sizeof(t_fractol))))
		return (0);
	new->mlx = mlx;
	new->sx = sx;
	new->sy = sy;
	new->sd = sd;
	new->xf1 = -2.1;
	new->xf2 = 0.6;
	new->yf1 = -1.2;
	new->yf2 = 1.2;
	new->i_max = 50;
	new->id = 1;
	new->img = mlx_new_image(mlx, sx
		/ sd, sy / sd);
	return (new);
}
