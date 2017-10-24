/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:53:40 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/24 04:20:15 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_move(int keycode, t_env *e)
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

int		key_hook2(int keycode, t_env *e)
{
	if (keycode == SWITCH)
	{
		ft_reset_env(e);
		if (e->f->nb < 4)
			e->f->nb++;
		else
			e->f->nb = 1;
	}
	else if (keycode == FREE_M)
		mlx_hook(e->win, MOTION_VECT, MOTION_PTR, ft_motion, e);
	return (0);
}

int		key_hook3(int keycode, t_env *e)
{
	ft_move(keycode, e);
	mlx_destroy_image(e->mlx, e->f->img);
	mlx_clear_window(e->mlx, e->win);
	e->f->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	ft_menu(e);
	ft_draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	double	tab1[7];
	double	tab2[7];

	if (keycode == ESC)
		exit(0);
	else if (keycode == SPACE && e->f->nb == 1)
		ft_switch_julia(e, tab1, tab2, 0);
	else if (keycode == SPACE && e->f->nb == 4)
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
	key_hook3(keycode, e);
	return (0);
}

int		ft_mouse(int button, int x, int y, t_env *e)
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
	else if ((button == L_MOUSE || button == DN_WHEEL) && \
		(x >= 0 && x <= WIN_W) && (y >= 0 && y <= WIN_H))
	{
		XMIN = e->f->mx - (dx * 1.5) / 2;
		XMAX = e->f->mx + (dx * 1.5) / 2;
		YMIN = e->f->my - (dy * 1.5) / 2;
		YMAX = e->f->my + (dy * 1.5) / 2;
	}
	return (ft_draw(e));
}
