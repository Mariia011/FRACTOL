/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:16:30 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/17 15:49:35 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
# include "./mlx/mlx.h"

double	map(double unscaled_num, double new_min, double new_max, double old_min,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min)
		+ new_min);
}

t_complex_num square_complex(t_complex_num z)
{
	t_complex_num	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

t_complex_num sum_complex(t_complex_num z1, t_complex_num z2)
{
	t_complex_num	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}
