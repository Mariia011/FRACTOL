/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:32:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/16 20:47:19 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration = 40;
	// fractal->shift_x = 0.0;
	// fractal->shift_y = 0.0;
	// fractal->zoom = 1.0;
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	// if (fractal->mlx_connection == NULL)
		// malloc_error(); // to DO
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection, WIDTH,
			HEIGHT fractal->name);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH,
			HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp,
												&fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
}
