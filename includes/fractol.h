/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:18:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/21 23:08:05 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>

# define WIN_W 1080
# define WIN_H 880

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define CORTEX 12
# define MINUS 13
# define SWITCH 1
# define FREE_M 0
# define ADD_D 14
# define LESS_D 15
# define COLOR_N 17
# define R_MOUSE 1
# define L_MOUSE 2
# define UP_WHEEL 4
# define DN_WHEEL 5
# define SPACE 49

# define XMIN  e->xmin
# define XMAX  e->xmax
# define YMIN  e->ymin
# define YMAX  e->ymax

# define MOTION_VECT		6
# define MOTION_PTR	(1L << 6)

typedef struct	s_img
{
	void		*img;
	double		pr;
	double		pi;
	double		cr;
	double		ci;
	double		mx;
	double		my;
	int			bpp;
	int			endian;
	int			size_line;
	char		*d;
	int			nb;
}				t_img;

typedef struct	s_env
{
	t_img		*f;
	void		*mlx;
	void		*win;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		iter;
	double		freq;
	int			color;
}				t_env;

int				ft_draw(t_env *e);
int				ft_instructions(void);
int				ft_color(int i, t_env *e);
int				key_hook(int keycode, t_env *e);
int				ft_motion(int x, int y, t_env *e);
int				ft_mouse(int button, int x, int y, t_env *e);
void			draw_pixel(t_img *f, int x, int y, int color);
int				ft_menu(t_env *e);
int				ft_julia(t_env *e, int x, int y);
int				ft_mandelbrot(t_env *e, int x, int y);
int				ft_tricorn(t_env *e, int x, int y);
void			ft_reset(t_env *e);
void			ft_switch_julia(t_env *e, double *tab1, double *tab2, int i);
int				ft_move(int keycode, t_env *e);
int				key_hook(int keycode, t_env *e);
int				key_hook2(int keycode, t_env *e);
int				ft_mouse(int button, int x, int y, t_env *e);
int				ft_motion(int x, int y, t_env *e);
int				ft_color(int i, t_env *e);
t_img			*init_img(char *s);
t_env			*init_env(char *s);

#endif
