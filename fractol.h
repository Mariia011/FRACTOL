/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marikhac <marikhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:08:19 by marikhac          #+#    #+#             */
/*   Updated: 2024/04/19 19:15:46 by marikhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#define RES_MINUS 27
#define RES_PLUS 24
#define KEY_UP 	126
#define KEY_DOWN 125
#define KEY_RIGHT 124
#define KEY_LEFT 123
#define KEY_ESCAPE 53

#define MOUSE_WHEELUP 5
#define MOUSE_WHEELDOWN 4
#define KEY_LOCK 49

typedef enum e_state {

	LOCK = 0,
	UNLOCK = 1

} t_state;


enum e_sh{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

# define ERROR_MESSAGE "Please enter ./ fractol mandelbrot or julia x yi\n"
# define WIDTH 800
# define HEIGHT 800

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define PRIYATNI_SALAT 0x00FF00 // RGB(0, 255, 0)
# define GAY 0x0000FF  // RGB(0, 0, 255)

# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF

typedef struct s_image
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int endian; //??
	int			line_len;
}				t_image;

typedef struct s_complex_num
{
	double		x;
	double		y;
}				t_complex_num;

typedef struct s_fractol
{
	char			*name;
	void			*mlx_connection;
	void			*mlx_window;
	t_image			img;
	int				hypothenuse;
	int				iteration;
	double 			shift_x;
	double 			shift_y;
	double 			zoom;
	t_complex_num 	c;
	t_complex_num 	julia;
	t_state 		state;
}				t_fractol;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			fractal_init(t_fractol *fractal, int bonus);

void			fractal_render(t_fractol *fractal);
int				destroy_handle(t_fractol *fractal);

t_complex_num	sum_complex(t_complex_num z1, t_complex_num z2);
t_complex_num	square_complex(t_complex_num z);
double			map(double unscaled_num, double new_min, double new_max, double old_max);
double			atodouble(char *s);

void 			bonus_handle(t_complex_num z, t_complex_num *c, t_fractol *fractal);
void			handle_pixel(int x, int y, t_fractol *fractal);
int				mouse_handle(int button, int x, int y, t_fractol *fractal);
int 			key_handler(int keysym, t_fractol *fractal);
int				julia_handle(int x, int y, t_fractol *fractal);
int				key_handler_bonus(int keysym, t_fractol *fractal);



#endif
