/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:00:41 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:06:32 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "stdio.h"

void	translate(t_env *e, int keycode)
{
	const double	k = e->zx * 10;

	if (keycode == DOWN)
	{
		CYMAX -= k;
		CYMIN -= k;
	}
	else if (keycode == UP)
	{
		CYMAX += k;
		CYMIN += k;
	}
	else if (keycode == LEFT)
	{
		CXMAX -= k;
		CXMIN -= k;
	}
	else if (keycode == RIGHT)
	{
		CXMAX += k;
		CXMIN += k;
	}
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
}

void	on_freq(int keycode, t_env *e)
{
	if (keycode == F)
		e->frequency *= 2;
	else if (keycode == D && e->frequency > 0.02)
		e->frequency /= 2;
}

void	change_fractal(t_env *e)
{
	ft_reset(e);
	if (e->f->frac_id == 1)
		e->f->frac_id = 2;
	else if (e->f->frac_id == 2)
		e->f->frac_id = 3;
	else if (e->f->frac_id == 3)
		e->f->frac_id = 1;
	else if (e->f->frac_id == 4)
		e->f->frac_id = 1;
}

int		key_hook(int keycode, t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	if (keycode == ESC)
		exit(0);
	else if (keycode == PLUS)
		MAX_ITER = (MAX_ITER < 8000) ? MAX_ITER * 2 : MAX_ITER;
	else if (keycode == MINUS)
		MAX_ITER = (MAX_ITER > 2) ? MAX_ITER / 2 : MAX_ITER;
	else if (keycode == N)
		e->color++;
	else if (keycode == B)
		e->color = e->color == 0 ? 2 : 0;
	else if (keycode == R)
		ft_reset(e);
	else if (keycode == PAGE_UP)
		change_fractal(e);
	translate(e, keycode);
	on_freq(keycode, e);
	draw_fractal(e);
	return (0);
}
