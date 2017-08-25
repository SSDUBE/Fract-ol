/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 15:01:39 by sdube             #+#    #+#             */
/*   Updated: 2016/10/09 15:12:27 by sdube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	view_instructions(void)
{
	ft_putstr("\nUsage:\n\n");
	ft_putstr("Type 1 for Mandelbrot\n");
	ft_putstr("Type 2 for Julia\n");
	ft_putstr("Type 3 for Curls\n");
	ft_putstr("Type 4 for Vector\n\n");
	ft_putstr("---------- Controls --------\n");
	ft_putstr("Mouse, left to zoom in\t");
	ft_putstr("Mouse, right  to zoom out\n");
	ft_putstr("Escape, to quit\n");
	ft_putstr("F, to increase frequency\n");
	ft_putstr("+, to  increase iteration\n");
	ft_putstr("-, to decrease iteration\n");
	ft_putstr("PageUp, to change between fractal\n");
	ft_putstr("N, to play with the colors\n");
	ft_putstr("B, to altern between black and white\n");
	ft_putstr("Arrow keys, to move a bit\n");
	return (-1);
}

int	main(int argc, char **argv)
{
	t_env	*e;

	if (argc != 2)
		return (view_instructions());
	e = init_env(argv[1]);
	draw_fractal(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, on_mouse_hook, e);
	mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, on_motion_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return (0);
}
