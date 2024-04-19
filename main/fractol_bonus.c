/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:35:49 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 18:47:06 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int main(int argc, char ** argv)
{
	t_fractol fractal;
	if (2 == argc && (!ft_strncmp(argv[1], "mandelbrot", 10) || !ft_strncmp(argv[1], "bonus", 5)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal, 1);
	}

	else if (4 == argc && !ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	{
		fractal.name = argv[1];
		fractal.julia.x = atodouble(argv[2]);
		fractal.julia.y = atodouble(argv[3]);
		fractal_init(&fractal, 1);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return(0);
}
