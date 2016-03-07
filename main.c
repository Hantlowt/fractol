/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 17:15:16 by alhote            #+#    #+#             */
/*   Updated: 2016/03/07 18:05:31 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	double	x1 = -2.1;
	double	x2 = 0.6;
	double	y1 = -1.2;
	double	y2 = 1.2;
 	int		image_x = 270;
 	int		image_y = 240;
	int		iteration_max = 50;
	int		x = 0;
	int		y = 0;

// on calcule la taille de l'image :
	double	zoom_x = image_x / (x2 - x1);
	double	zoom_y = image_y / (y2 - y1);

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
	return (0);
}
