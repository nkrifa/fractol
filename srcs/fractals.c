/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:50:04 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/23 22:31:57 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_julia(t_env *e, int x, int y)
{
	t_img	*f;
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

int		ft_trijulia(t_env *e, int x, int y)
{
	t_img	*f;
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
		f->pi = -2 * f->pi * tmp + f->ci;
	}
	return (i);
}

int		ft_mandelbrot(t_env *e, int x, int y)
{
	t_img	*f;
	int		i;
	double	tmp;

	f = e->f;
	i = -1;
	f->pr = 0.0;
	f->pi = 0.0;
	f->cr = XMIN + ((double)x * (XMAX - XMIN) / WIN_W);
	f->ci = YMIN + ((double)y * (YMAX - YMIN) / WIN_H);
	while (i < e->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
	{
		tmp = f->pr;
		f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
		f->pi = 2 * f->pi * tmp + f->ci;
		i++;
	}
	return (i);
}

int		ft_tricorn(t_env *e, int x, int y)
{
	t_img	*f;
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
