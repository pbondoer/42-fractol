/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2016/11/17 02:20:26 by lemon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

#include <stdio.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	printf("key %d down\n", key);
	if (key == 53 || key == 65307) // esc
		exit(EXIT_SUCCESS);
	if (key == 65450) // multiply
		mlx->viewport.max *= 2;
	if (key == 65455) // divide
		mlx->viewport.max /= 2;
	if (key == 69 || key == 65451) // plus
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, 1 / ZOOM);
	if (key == 78 || key == 65453) // minus
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->viewport, ZOOM);
	//TODO: rewrite this as generic viewport functions
	double w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	double h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == 65362) // up
		mlx->viewport.offy -= h * 0.05f;
	if (key == 65364) // down
		mlx->viewport.offy += h * 0.05f;
	if (key == 65361) // left
		mlx->viewport.offx -= w * 0.05f;
	if (key == 65363) // right
		mlx->viewport.offx += w * 0.05f;
	render(mlx);
	return (0);
}
