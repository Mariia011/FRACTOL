 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:32:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 15:43:27 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractol *fractal)
{
	fractal->escape_value = 4;
	fractal->iteration = 20;
	fractal->zoom = 1;
	fractal->c.x = -0.8;
	fractal->c.y = 0.156;
}

static void events_init(t_fractol *fractal)
{
	mlx_hook(fractal->mlx_window, ON_KEYDOWN, 0, key_handler, fractal);
	mlx_hook(fractal->mlx_window, ON_MOUSEDOWN, 0, mouse_handle, fractal);
	mlx_hook(fractal->mlx_window, ON_DESTROY, 0, destroy_handle, fractal);
}

void	fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(EXIT_FAILURE);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
	WIDTH,HEIGHT,fractal->name);
	if (NULL == fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp,
												&fractal->img.line_len, &fractal->img.endian);
	data_init(fractal);
	events_init(fractal);
}
