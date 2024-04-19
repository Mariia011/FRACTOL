/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:53:49 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 15:22:12 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_handle(t_fractol *fractal)
{
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

int	mouse_handle(int button, int x, int y, t_fractol *fractal)
{
	(void)x;
	(void)y;
	if (MOUSE_WHEELUP == button)
		fractal->zoom *= 0.7;
	else if (MOUSE_WHEELDOWN == button)
		fractal->zoom *= 1.3;
	fractal_render(fractal);
	return (0);
}

int key_handler(int keysym, t_fractol *fractal)
{
	double shift_factor = 0.5;
	if (RES_MINUS == keysym)
		fractal->iteration -= 10;
	else if (RES_PLUS == keysym)
		fractal->iteration += 10;
	else if (KEY_LEFT == keysym)
		fractal->shift_x -= shift_factor * fractal->zoom;
	else if (KEY_RIGHT == keysym)
		fractal->shift_x += shift_factor * fractal->zoom;
	else if (KEY_DOWN == keysym)
		fractal->shift_y -= shift_factor * fractal->zoom;
	else if (KEY_UP == keysym)
		fractal->shift_y += shift_factor * fractal->zoom;
	else if (KEY_ESCAPE == keysym)
		destroy_handle(fractal);
	fractal_render(fractal);
	return 0;
}

int	julia_handle(int x, int y, t_fractol *fractal)
{
		fractal->julia.x = (map(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		fractal->julia.y = (map(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		fractal_render(fractal);
	return (0);
}
