/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:50:20 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/15 20:15:14 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractol_render(t_fractol *fractal)
{
	int x;
	int y;

	y = 0;
	while(WIDTH > y++)
	{
		handle_pixel(x, y, fractal);
	}
}

void handle_pixel(int x, int  y, t_fractol *fractal)
{

}
