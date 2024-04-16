/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:19 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/16 20:41:03 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ERROR_MESSAGE "Please enter \n\t ./ fractol mandelbrot or any"
# define WIDTH 800
# define HEIGHT 800

# include "./MiniLibX/mlx.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)

typedef struct s_image
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int 		endian; //??
	int			line_len;
}				t_image;

typedef struct s_complex_num
{
	double		x;
	double		y;
}				t_complex_num;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_image		img;
	double		hypothenuse;
	int			escape_value;
	int			iteration;

}				t_fractol;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			fractal_init(t_fractol *fractal);
void			handle_pixel(int x, int i, t_fractol *fractal);
void			fractol_render(t_fractol *fractal);

t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2);
t_complex_num	square_complex(t_complex_num z);
double			map(double unscaled_num, double new_min, double new_max,
					double old_min, double old_max);

#endif
