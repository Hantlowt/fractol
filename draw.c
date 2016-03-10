/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:53:23 by alhote            #+#    #+#             */
/*   Updated: 2016/03/10 17:09:22 by alhote           ###   ########.fr       */
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

	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	//printf("%x\n", data);
	data[y * sizeline + x * 4] = color;
	data[y * sizeline + x * 4 + 1] = color >> 8;
	data[y * sizeline + x * 4 + 2] = color >> 16;
	//printf("%d\n", data[y * sizeline + x * 4]);
	//printf("%d %d %d\n", data[y * sizeline + x * (bpp / 8)], data[y * sizeline + x * (bpp / 8) + 1], data[y * sizeline + x * (bpp / 8) + 2]);
}
