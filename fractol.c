/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:24 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/15 20:15:14 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"





int main(int argc, char **argv)
{
	t_fractol fractal;
	if((2 != argc && 0 != ft_strncmp(argv[1], "Mandelbrot", 10))
		|| (4 != argc && 0 != ft_strncmp(argv[1], "Julia", 5)))
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILE);
		exit(EXIT_FAILURE);
	}


}
