/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:11:44 by kyanagis          #+#    #+#             */
/*   Updated: 2025/07/04 19:03:43 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	destroy_mlx(t_fract *f)
{
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

int	close_win(t_fract *f)
{
	destroy_mlx(f);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_fract(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_W, WIN_H, "fractol");
	f->img.img = mlx_new_image(f->mlx, WIN_W, WIN_H);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line,
			&f->img.endian);
	f->zoom = 1.0;
	f->off_x = 0;
	f->off_y = 0;
	f->iter_base = 40;
	f->hue = 0;
	render_frame(f);
	mlx_hook(f->win, 17, 0, close_win, f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
}
