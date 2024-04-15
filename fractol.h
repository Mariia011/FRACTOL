/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:19 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/15 19:28:00 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define ERROR_MESSAGE "Please enter \n\t "./fractol mandelbrot\" or any"
#define WIDTH 800
#define HEIGHT 800


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#include "mlx.h"
#include "libft.h"

typedef struct s_image{
	void	*img_ptr; //pointer to anorher image struct
	char	*pixels_ptr;
	int		bpp;
	int 	endian; //??
	int 	line_len;
}	t_image;

typedef struct s_fractol{
	char 	*name;
	void	*mlx_init;
	void	*mlx_window;
	t_image	img;
} t_fractol;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
