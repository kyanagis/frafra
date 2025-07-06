/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski_gasket.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 07:27:16 by kyanagis          #+#    #+#             */
/*   Updated: 2025/06/16 07:27:24 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	sierpinski(int cx, int cy)
{
	int	ix;
	int	iy;

	ix = (int)((cx + 2.0) * 128);
	iy = (int)((cy + 2.0) * 128);
	return (!((ix & iy) != 0));
}
