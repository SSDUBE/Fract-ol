/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:07:54 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:09:20 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		draw_mandel(t_env *e, int x, int y)
{
	t_frac			*f;
	register int	i;
	register double	zr;
	register double	zi;

	i = -1;
	f = e->f;
	f->pi = CYMAX - (long double)y * e->zy;
	f->pr = CXMIN + (long double)x * e->zx;
	f->ni = 0;
	f->nrl = 0;
	zr = SQUARE(0);
	zi = SQUARE(0);
	while (++i < MAX_ITER && (zr + zi < 4))
	{
		f->ni = 2 * f->ni * f->nrl + f->pi;
		f->nrl = (zr - zi) + f->pr;	
		zr = SQUARE(f->nrl);
		zi = SQUARE(f->ni);
	}
	return (i);
}

int		draw_julia(t_env *e, int x, int y)
{
	t_frac					*f;
	register int			i;
	register long double	zr;
	register long double	zi;

	i = -1;
	f = e->f;
	f->ni = CYMAX - (long double)y * e->zy;
	f->nrl = CXMIN + (long double)x * e->zx;
	zr = SQUARE(f->nrl);
	zi = SQUARE(f->ni);
	while (++i < MAX_ITER && (zr + zi) < 4)
	{
		f->ni = 2 * f->ni * f->nrl + f->ci;
		f->nrl = zr - zi + f->cr;
		zr = SQUARE(f->nrl);
		zi = SQUARE(f->ni);
	}
	return (i);
}

int		draw_curls(t_env *e, int x, int y)
{
	t_frac					*f;
	register int			i;
	register long double	zr;
	register long double	zi;

	i = -1;
	f = e->f;
	f->pi = CYMAX - (long double)y * e->zy;
	f->pr = CXMIN + (long double)x * e->zx;
	f->nrl = f->pr;
	f->ni = f->pi;
	zr = SQUARE(f->nrl);
	zi = SQUARE(f->ni);
	while (++i < MAX_ITER && (zr + zi) < 4)
	{
        f->ni = 2 * fabs(f->nrl * f->ni) + floor(f->pi);
        f->nrl = zr - zi + floor(f->pr);
		zr = SQUARE(f->nrl);
		zi = SQUARE(f->ni);
	}
	return (i);
}

double	function(double a)
{
    return (a);
}

int		draw_vector(t_env *e, int x, int y)
{
    t_frac					*f;
    register int			i;
    register long double	zr;
    register long double	zi;
    
    i = -1;
    f = e->f;
    f->ni = CYMAX - (long double)y * e->zy;
    f->nrl = CXMIN + (long double)x * e->zx;
    zr = SQUARE(f->nrl);
    zi = SQUARE(f->ni);
    while (++i < MAX_ITER && (zr + zi) < 4)
    {
        f->ni = 2 * f->ni * f->nrl + floor(f->ci);
        f->nrl = zr - zi + floor(f->cr);
        zr = SQUARE(f->nrl);
        zi = SQUARE(f->ni);
    }
    return (i);
}
