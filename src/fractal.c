/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:00:53 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:07:44 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel(t_frac *e, int x, int y, int color)
{
	const unsigned int	bytes = e->bpp / 8;
	const unsigned int	p = x * bytes + y * e->line_size;
	size_t				i;

	i = 0;
	while (i < bytes)
	{
		e->d[p + i] = color;
		color >>= 8;
		i++;
	}
}

int		get_fractal(t_env *e, int x, int y)
{
	if (e->f->frac_id == 1)
		return (draw_mandel(e, x, y));
	else if (e->f->frac_id == 2)
		return (draw_julia(e, x, y));
	else if (e->f->frac_id == 3)
		return (draw_curls(e, x, y));
	else if (e->f->frac_id == 4)
		return (draw_vector(e, x, y));
	else
		return (-1);
}

int		draw_fractal(t_env *e)
{
	int				c;
	int				ch;
	register int	x;
	register int	y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_Y)
		{
			ch = get_fractal(e, y, x);
			c = make_color(ch, e);
			put_pixel(e->f, y, x, c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->f->img, 0, 0);
	return (0);
}
