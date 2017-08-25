/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:01:27 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:11:27 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	set_value(t_env *e, double dcr, double dci)
{
	dcr = e->f->cr / 2;
	dci = e->f->ci / 2;
	CXMIN = e->f->mx - dcr;
	CXMAX = e->f->mx + dcr;
	CYMIN = e->f->my - dci;
	CYMAX = e->f->my + dci;
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
}

int			on_mouse_hook(int btn, int x, int y, t_env *e)
{
	register double	dcr;
	register double	dci;

	dcr = x;
	dci = y;
	e->f->cr = CXMAX - CXMIN;
	e->f->ci = CYMAX - CYMIN;
	e->f->mx = ((double)x / WIN_X * e->f->cr) - e->f->cr / 2 + e->f->mx;
	e->f->my = (double)(WIN_Y - y) / WIN_Y * e->f->ci - e->f->ci / 2 + e->f->my;
	if ((btn == M_LEFT || btn == M_UP) && x <= WIN_X && y <= WIN_Y)
	{
		e->f->cr /= 1.5;
		e->f->ci /= 1.5;
	}
	else if ((btn == M_RIGHT || btn == M_DOWN) && x <= WIN_X && y <= WIN_Y)
	{
		e->f->cr *= 1.5;
		e->f->ci *= 1.5;
	}
	set_value(e, dcr, dci);
	return (draw_fractal(e));
}

int			on_motion_hook(int x, int y, t_env *e)
{
	if (x >= 0 && y >= 0 && x <= WIN_X && y <= WIN_Y)
	{
		if (e->f->frac_id == 2)
		{
			e->f->ci = CYMAX - (double)y * e->zy;
			e->f->cr = CXMIN + (double)x * e->zx;
			return (draw_fractal(e));
		}
	}
	return (0);
}
