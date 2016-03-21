/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:53:23 by alhote            #+#    #+#             */
/*   Updated: 2016/03/21 20:56:07 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int		rgbtoint(int r, int v, int b)
{
	return (b + (v * 256) + (r * 65536));
}

void	img_pxl(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	data[y * sizeline + x * 4] = color;
	data[y * sizeline + x * 4 + 1] = color >> 8;
	data[y * sizeline + x * 4 + 2] = color >> 16;
}
