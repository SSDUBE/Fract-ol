/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:01:04 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:10:41 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void			ft_reset(t_env *e)
{
	t_frac	*f;

	f = e->f;
	CXMAX = 2.0;
	CXMIN = -2.0;
	CYMIN = -2.0;
	CYMAX = 1.5;
	f->cr = -0.8;
	f->ci = 0.156;
	f->mx = 0.0;
	f->my = 0.0;
	f->nrl = 0.0;
	f->ni = 0.0;
	e->frequency = 0.1;
	e->iter = 16;
	e->color = 42;
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
}

static t_mod	*init_mod(void)
{
	t_mod	*m;

	m = malloc(sizeof(t_mod) * 1);
	m->xmax = 2.0;
	m->xmin = -2.0;
	m->ymin = -2.0;
	m->ymax = 1.5;
	return (m);
}

t_frac			*init_frac(char *av)
{
	t_frac	*f;

	f = malloc(sizeof(t_frac) * 1);
	f->cr = -0.8;
	f->ci = 0.156;
	f->mx = 0.0;
	f->my = 0.0;
	f->frac_id = ft_atoi(av);
	f->nrl = 0.0;
	f->ni = 0.0;
	if (f->frac_id >= 1 && f->frac_id < 5)
		return (f);
	view_instructions();
	exit(0);
	return (NULL);
}

t_env			*init_env(char *av)
{
	t_env	*e;

	e = malloc(sizeof(t_env) * 1);
	e->m = init_mod();
	e->f = init_frac(av);
	e->mlx = mlx_init();
	e->f->img = mlx_new_image(e->mlx, WIN_X, WIN_Y);
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "Fractol");
	e->f->d = mlx_get_data_addr(e->f->img, &e->f->bpp, &e->f->line_size, &e->f->endian);
	e->t = (double)time(NULL);
	e->frequency = 0.1;
	e->iter = 16;
	e->color = 42;
	e->zx = ((CXMAX - CXMIN) / (WIN_X - 1));
	e->zy = ((CYMAX - CYMIN) / (WIN_Y - 1));
	return (e);
}
