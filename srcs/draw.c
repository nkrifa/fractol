/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:52:07 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/23 22:25:21 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_draw(t_env *e)
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
			else if (e->f->nb == 4)
				color = ft_color(ft_trijulia(e, x, y), e);
			draw_pixel(e->f, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (0);
}

int		ft_color(int i, t_env *e)
{
	int		red;
	int		green;
	int		blue;
	double	co;

	if (i == e->iter)
		return (0);
	co = e->freq * (i + 2);
	red = cos(co) * 127 + 128;
	green = cos(co + e->color) * 127 + 128;
	blue = cos(co + 2 * e->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green);
}

void	draw_pixel(t_img *f, int x, int y, int color)
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
