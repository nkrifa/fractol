/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:56:04 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/23 22:31:23 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_reset_env(t_env *e)
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
	e->freq += 0.1;
	e->iter = 16.0;
	e->color = 60;
}

t_img	*init_img(char *s)
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
	e->freq = 0.7;
	e->iter = 16.0;
	e->color = 60;
	return (e);
}

int		ft_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, WIN_H + 5, 0xFFFFFF, "COMMANDES");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 40, 0xFFFFFF, "ESC => Quitter");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 70, 0xFFFFFF,
		"Clic Gauche / Molette Haut => Zoomer");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 100, 0xFFFFFF,
		"Clic Droit  / Molette Bas => Dezoomer");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 130, 0xFFFFFF,
		"A => Navigation avec la souris dans Julia");
	mlx_string_put(e->mlx, e->win, 70, WIN_H + 160, 0xFFFFFF,
		"T => Palette des couleurs");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 40, 0xFFFFFF,
		"Q / W => Facteur des couleurs");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 70, 0xFFFFFF,
		"S => Changer de fractal");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 100, 0xFFFFFF,
		"E / R => Profondeur d'iteration");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 130, 0xFFFFFF,
		"ESPACE => Variation parametres Julia");
	mlx_string_put(e->mlx, e->win, 650, WIN_H + 160, 0xFFFFFF,
		"Fleches du clavier => Deplacement");
	return (0);
}

int		ft_motion(int x, int y, t_env *e)
{
	if (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H && e->f->nb == 1)
	{
		e->f->cr = XMIN + ((x * XMAX) / WIN_W);
		e->f->ci = YMIN + ((y * YMAX) / WIN_H);
	}
	return (ft_draw(e));
}
