/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:39:33 by nkrifa           #+#    #+#             */
/*   Updated: 2017/10/21 02:55:11 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fractol.h"




int			ft_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, WIN_H + 5, 0xFFFFFF, "COMMANDES");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 40, 0xFFFFFF,"ESC => Quitter");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 70, 0xFFFFFF, \
		"Clic Gauche / Molette Haut => Zoomer");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 100, 0xFFFFFF, \
		"Clic Droit  / Molette Bas => Dezoomer");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 130, 0xFFFFFF, \
		"A => Navigation avec la souris dans Julia");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 160, 0xFFFFFF, \
		"T => Palette des couleurs");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 40, 0xFFFFFF, \
		"Q / W => Facteur des couleurs");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 70, 0xFFFFFF, \
		"S => Changer de fractal");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 100, 0xFFFFFF, \
		"E / R => Profondeur d'iteration");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 130, 0xFFFFFF, \
		"ESPACE => Variation parametres Julia");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 160, 0xFFFFFF, \
		"Fleches du clavier => Deplacement"); 
	return (0);
}

int	ft_julia(t_env *e, int x, int y)
{
	t_img		*f;
	int		i;
	double	tmp;

	f = e->f;
	i = -1;
	f->pr = XMIN + ((double)x * (XMAX - XMIN) / WIN_W);
	f->pi = YMIN + ((double)y * (YMAX - YMIN) / WIN_H);
	while (++i < e->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

   int	ft_mandelbrot(t_env *e, int x, int y)
{
	t_img		*f;
	int		i;
	double	tmp;

	f = e->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = XMIN + ((double)x * (XMAX - XMIN) / WIN_W);
	f->ci = YMIN + ((double)y * (YMAX - YMIN) / WIN_H);
	while (++i < e->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
	}
	return (i);
}

   int	ft_tricorn(t_env *e, int x, int y)
{
	t_img		*f;
	int		i;
	double	tmp;

	f = e->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = XMIN + ((double)x * (XMAX - XMIN) / WIN_W);
	f->ci = YMIN + ((double)y * (YMAX - YMIN) / WIN_H);
	while (++i < e->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = -2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int			ft_draw(t_env *e)
{
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (e->f->nb == 1)
				color = ft_color(ft_julia(e, x, y), e);
			else if (e->f->nb == 2)
				color = ft_color(ft_mandelbrot(e, x, y), e);
			else if (e->f->nb == 3)
				color = ft_color(ft_tricorn(e, x, y), e);
			draw_pixel(e->f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (0);
}

   void	ft_reset(t_env *e)
{
	e->f->cr = -1.1380;
	e->f->ci = 0.2403;
	e->f->pr = 0.0;
	e->f->pi = 0.0;
	e->f->mx = 0.0;
	e->f->my = 0.0;
	e->xmin = -3.2;
	e->ymin = -3.2;
	e->xmax = 3.4;
	e->ymax = 3.4;
	e->freq = 0.1;
	e->iter = 16.0;
	e->color = 88;
}

   void	ft_switch_julia(t_env *e, double *tab1, double *tab2, int i)
{
	tab1[0] = -0.772691322542185;
	tab2[0] = 0.124281466072787;
	tab1[1] = -0.7927;
	tab2[1] = 0.1609;
	tab1[2] = -1.1380;
	tab2[2] = 0.2403;
	tab1[3] = -0.1225;
	tab2[3] = 0.7449;
	tab1[4] = -0.32;
	tab2[4] = 0.043;
	tab1[5] = -0.0986;
	tab2[5] = -0.65186;
	tab1[6] = -0.3380;
	tab2[6] = -0.6230;
	while (e->f->cr != tab1[i] && i < 7)
		i++;
	if (i < 6)
	{
		e->f->cr = tab1[i + 1];
		e->f->ci = tab2[i + 1];
	}
	else if ((e->f->cr = tab1[0]) != 4.0)
		e->f->ci = tab2[0];
}

   int	ft_move(int keycode, t_env *e)
{
	double	c;

	c = ((XMAX - XMIN) / WIN_W) * 10;
	if (keycode == LEFT)
	{
		XMIN += c;
		XMAX += c;
	}
	else if (keycode == RIGHT)
	{
		XMIN -= c;
		XMAX -= c;
	}
	else if (keycode == DOWN)
	{
		YMIN -= c;
		YMAX -= c;
	}
	else if (keycode == UP)
	{
		YMIN += c;
		YMAX += c;
	}
	return (0);
}

   int	key_hook2(int keycode, t_env *e)
{
	if (keycode == SWITCH)
	{
		ft_reset(e);
		if (e->f->nb < 3)
			e->f->nb++;
		else
			e->f->nb = 1;
	}
	else if (keycode == FREE_M)
		mlx_hook(e->win, MOTION_VECT, MOTION_PTR, ft_motion, e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	double	tab1[7];
	double	tab2[7];

	if (keycode == ESC)
		exit(0);
	else if (keycode == SPACE && e->f->nb == 1)
		ft_switch_julia(e, tab1, tab2, 0);
	else if (keycode == ADD_D)
		e->iter = (e->iter < 8000) ? e->iter * 2 : e->iter;
	else if (keycode == LESS_D)
		e->iter = (e->iter > 2) ? e->iter / 2 : e->iter;
	else if (keycode == COLOR_N)
		e->color++;
	else if (keycode == CORTEX)
		e->freq = (e->freq < 200) ? e->freq * 2 : e->freq;
	else if (keycode == MINUS)
		e->freq = (e->freq > 0.1) ? e->freq / 2 : e->freq;
	key_hook2(keycode, e);
	ft_move(keycode, e);
	mlx_destroy_image(e->mlx, e->f->img);
	mlx_clear_window(e->mlx, e->win);
	e->f->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	ft_menu(e);
	ft_draw(e);
	return (0);
}

int			ft_mouse(int button, int x, int y, t_env *e)
{
	double	dx;
	double	dy;

	dx = XMAX - XMIN;
	dy = YMAX - YMIN;
	e->f->mx = ((double)(x) / WIN_W * dx) - dx / 2 + e->f->mx;
	e->f->my = (double)(y) / WIN_H * dy - dy / 2 + e->f->my;
	if ((button == R_MOUSE || button == UP_WHEEL) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		XMIN = e->f->mx - (dx / 1.5) / 2;
		XMAX = e->f->mx + (dx / 1.5) / 2;
		YMIN = e->f->my - (dy / 1.5) / 2;
		YMAX = e->f->my + (dy / 1.5) / 2;
	}
	else if ((button == L_MOUSE || button == DN_WHEEL) && (x >= 0 && x <= WIN_W)\
			&& (y >= 0 && y <= WIN_H))
	{
		XMIN = e->f->mx - (dx * 1.5) / 2;
		XMAX = e->f->mx + (dx * 1.5) / 2;
		YMIN = e->f->my - (dy * 1.5) / 2;
		YMAX = e->f->my + (dy * 1.5) / 2;
	}
	return (ft_draw(e));
}

int			ft_motion(int x, int y, t_env *e)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && e->f->nb == 1)
	{
		e->f->cr = XMIN + ((x * XMAX) / WIN_W);
		e->f->ci = YMIN + ((y * YMAX) / WIN_H);
	}
	return (ft_draw(e));
}



int				ft_color(int i, t_env *e)
{
	int		red;
	int		green;
	int		blue;
	double	co;

	if (i == e->iter)
		return (0);
	co = e->freq * (i + 1);
	red = cos(co) * 127 + 128;
	green = cos(co + e->color) * 127 + 128;
	blue = cos(co + 2 * e->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void			draw_pixel(t_img *f, int x, int y, int color)
{
	int				i;
	unsigned int	p;

	i = 0;
	p = x * (f->bpp / 8) + y * (f->size_line);
	while (i < (f->bpp / 8))
	{
		f->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

   t_img		*init_img(char *s)
{
	t_img	*f;

	if (!(f = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	f->cr = -1.1380;
	f->ci = 0.2403;
	f->pr = 0.0;
	f->pi = 0.0;
	f->mx = 0.0;
	f->my = 0.0;
	f->nb = ft_atoi(s);
	return (f);
}

   t_env	*init_env(char *s)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!(e->f = init_img(s)))
		return (NULL);
	e->mlx = mlx_init();
	e->f->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H + 200, "fractol");
	ft_menu(e);
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->size_line\
				, &e->f->endian);
	e->xmin = -3.2;
	e->ymin = -3.2;
	e->xmax = 3.4;
	e->ymax = 3.4;
	e->freq = 0.1;
	e->iter = 16.0;
	e->color = 88;
	return (e);
}

int				main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2 || ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 3)
	{
		ft_putstr("Error, put 1 / 2 / 3 as param to get Julia / Mandelbrot / Tricorn");
		return (0);
	}
	if ((e = init_env(argv[1])) != NULL)
	{
		ft_draw(e);
		mlx_key_hook(e->win, key_hook, e);
		mlx_mouse_hook(e->win, ft_mouse, e);
		mlx_loop(e->mlx);
		mlx_destroy_window(e->mlx, e->win);
	}
	return (0);
}
