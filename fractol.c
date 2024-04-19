/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:24 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 15:38:53 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char ** argv)
{
	t_fractol fractal;
	if((2 != argc) || (ft_strncmp(argv[1], "mandelbrot", 10)
		 && ft_strncmp(argv[1], "bonus", 5)))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	// else if(argc == 4 && !ft_strncmp(argv[1], "julia", ft_strlen("julia")))
	// {
	// 	fractal.julia.x = atodouble(argv[2]);
	// 	fractal.julia.y = atodouble(argv[3]);
	// 	fractal_init(&fractal);
	// }
	fractal.name = argv[1];
	fractal_init(&fractal);
	fractal_render(&fractal);
	mlx_loop(fractal.mlx_connection);
	return(0);
}
