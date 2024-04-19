/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:50:20 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 15:43:37 by marikhac         ###   ########.fr       */
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
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

static void	pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}


t_complex_num bonus_handle(t_complex_num z, t_complex_num c, t_fractol *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", ft_strlen("mandelbrot")))
		return z;
	return fractal->c;
}

 void	handle_pixel(int x, int y, t_fractol *fractal)
{
	t_complex_num	z;
	t_complex_num	c;
	int				n;
	int				color;

	z.x = (map(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	bonus_handle(z, c, fractal);
	n = 0;
	while (n < fractal->iteration)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			printf("%f\n", (z.x * z.x) + (z.y * z.y));
			color = map(n, BLACK, WHITE, fractal->iteration);
			pixel_put(x, y, &fractal->img, color);
			return ;
		}
		n++;
	}
	pixel_put(x, y, &fractal->img, ELECTRIC_BLUE);
}
