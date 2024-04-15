/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:32:07 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/15 20:15:14 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractal_init(t_fractol *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		malloc_error(); //to DO
	if (NULL == fractal->mlx_window)
	{
		mlx_destroy_display(fractal->mlx_connection, WIDTH, HEIGHT
							fractal->name);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (NULL == fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_wimdow)  ;
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr);

}
