/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:30:15 by kyanagis          #+#    #+#             */
/*   Updated: 2025/07/01 19:51:36 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage:\n");
	ft_printf("  ./fractol mandelbrot\n");
	ft_printf("  ./fractol julia <real> <imag>\n");
	ft_printf("  ./fractol burn\n");
	ft_printf("  ./fractol sier\n");
}

static int	is_number(const char *s)
{
	int	i;

	i = 0;
	if (s[0] == '+' || s[0] == '-')
		i = 1;
	while (s[i])
	{
		if (s[i] != '.' && !ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (i == 0 || (i == 1 && (s[0] == '+' || s[0] == '-')))
		return (0);
	return (1);
}

static int	parse_julia(t_fract *f, int ac, char **av)
{
	f->kind = JULIA;
	if (ac == 4 && is_number(av[2]) && is_number(av[3]))
	{
		f->c_re = ft_atof(av[2]);
		f->c_im = ft_atof(av[3]);
		return (1);
	}
	else if (ac == 2)
	{
		f->c_re = -0.8;
		f->c_im = 0.156;
		return (1);
	}
	return (0);
}

static int	parse_args(t_fract *f, int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		return (0);
	}
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
	{
		f->kind = MANDELBROT;
		return (1);
	}
	else if ((ft_strcmp(av[1], "julia") == 0) && parse_julia(f, ac, av))
		return (1);
	else if (ft_strcmp(av[1], "burn") == 0)
	{
		f->kind = BURNING_SHIP;
		return (1);
	}
	else if (ft_strcmp(av[1], "sier") == 0)
	{
		f->kind = SIERPINSKI;
		return (1);
	}
	print_usage();
	return (0);
}

int	main(int ac, char **av)
{
	t_fract	f;

	if (!parse_args(&f, ac, av))
		return (1);
	init_fract(&f);
	mlx_loop(f.mlx);
	return (0);
}
