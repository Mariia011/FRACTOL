/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:50:20 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/17 17:08:44 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_render(t_fractol *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (WIDTH > y)
	{
		x = 0;
		while (HEIGHT > x)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}


static void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;
		printf("color : %d\n", color);

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

 void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				n;
	int				color;

	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	n = 0;
	while (n < fractal->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(n, BLACK, WHITE, 0, fractal->iteration);
			pixel_put(x, y, &fractal->img, RED);
			return ;
		}
		n++;
	}
	pixel_put(x, y, &fractal->img, RED);
}
