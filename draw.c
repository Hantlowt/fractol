/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:53:23 by alhote            #+#    #+#             */
/*   Updated: 2016/03/09 19:09:41 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	image_put_pixel(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	x = 0;
	y = 0;
	color = 0;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	printf("%d, %d, %d\n", bpp, sizeline, endian);
}
