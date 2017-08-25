/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:00:11 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:03:05 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include "keys.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

# define WIN_X 650
# define WIN_Y 650
# define MAX_ITER e->iter

# define CXMIN e->m->xmin
# define CXMAX e->m->xmax
# define CYMIN e->m->ymin
# define CYMAX e->m->ymax

# define SQUARE(x) x * x

# define PIXW e->zx
# define PIXH e->zy

# define MEH PIXW/PIXH
# define MK_MI	78

# define MB_L	1
# define MB_R	2
# define MB_M	3
# define MB_UP	5
# define MB_DW	4

# define MOTION_NOTIFY			6
# define PTR_MOTION_MASK		(1L << 6)

typedef struct	s_mod
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		omx;
	double		omy;

}				t_mod;

typedef struct	s_frac
{
	char		*d;
	double		cr;
	double		ci;
	double		pr;
	double		pi;
	double		nrl;
	double		ni;
	double		orl;
	double		oi;
	double		zoom;

	double		mx;
	double		my;

	int			frac_id;
	int			bpp;
	int			endian;
	int			line_size;
	void		*img;

}				t_frac;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_frac		*f;
	t_mod		*m;
	double		t;
	double		frequency;
	double		iter;
	double		zx;
	double		zy;
	int			color;
}				t_env;

typedef struct	s_complex
{
	double		img;
	double		real;
}				t_complex;

int				key_hook(int keycode, t_env *e);
int				on_motion_hook(int x, int y, t_env *e);
int				on_mouse_hook(int button, int x, int y, t_env *e);

int				make_color(int i, t_env *e);
int				lerp(float v0, float v1, float t);
float			normalize(double x, double y, int i);

t_frac			*init_frac(char *av);
t_env			*init_env(char *av);

int				draw_julia(t_env *e, int x, int y);
int				draw_mandel(t_env *e, int x, int y);
int				draw_curls(t_env *e, int x, int y);
int				draw_vector(t_env *e, int x, int y);
int				draw_fractal(t_env *e);

int				view_instructions(void);
void			ft_reset(t_env *e);

t_complex		new_complex(double a, double b);
t_complex		add_complex(t_complex a, t_complex b);
t_complex		mul_complex(t_complex a, t_complex b);
t_complex		pow_complex(t_complex a);
t_complex		div_complex(t_complex a, t_complex b);
double			abs_complex(t_complex a);

#endif
