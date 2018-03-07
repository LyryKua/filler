/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:47:24 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:28 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "visualization.h"
#include "libft.h"

void		put_pixel(t_graphics *graphics, int y, int x, unsigned int color)
{
	if (x >= graphics->w || x < 0 || y >= graphics->h || y < 0)
		return ;
	ft_memcpy(graphics->addr + (x * 4 + y * graphics->sl), &color, 4);
}

t_graphics	*init_graphics(int w, int h, char *title)
{
	t_graphics	*graphics;

	graphics = (t_graphics *)malloc(sizeof(t_graphics));
	graphics->mlx = mlx_init();
	graphics->win = mlx_new_window(graphics->mlx, w, h, title);
	graphics->img = mlx_new_image(graphics->mlx, w, h);
	graphics->addr = mlx_get_data_addr(graphics->img, &graphics->bpp,
												&graphics->sl, &graphics->e);
	graphics->w = w;
	graphics->h = h;
	graphics->put_pixel = put_pixel;
	return (graphics);
}
