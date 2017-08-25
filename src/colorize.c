/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:00:34 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:05:25 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	make_color(int i, t_env *e)
{
	register double	c;
	register int	red;
	register int	green;
	register int	blue;

	if (i == MAX_ITER)
		return (0);
	c = e->frequency * (i + 1);
	red = cos(c) * 127 + 128;
	green = cos(c + e->color) * 127 + 128;
	blue = cos(c + e->color + e->color) * 127 + 128;
	return ((red << 16) + (blue << 8) + green) ^ 255;
}
