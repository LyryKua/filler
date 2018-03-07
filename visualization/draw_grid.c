/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:48:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 19:48:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "visualization.h"
#include "libft.h"

void	horizontal(t_graphics *graphics, int x)
{
	int	i;
	int	j;
	int	finish;

	i = x;
	while (i < graphics->h)
	{
		finish = i + (int)rint(x * 0.1);
		while (i < finish)
		{
			j = 0;
			while (j < graphics->w)
			{
				graphics->put_pixel(graphics, i, j, 0x111111);
				j++;
			}
			i++;
		}
		i += x;
	}
}

void	vertical(t_graphics *graphics, int x)
{
	int	i;
	int	j;
	int	finish;

	i = x;
	while (i < graphics->w)
	{
		finish = i + (int)rint(x * 0.1);
		while (i < finish)
		{
			j = 0;
			while (j < graphics->h)
			{
				graphics->put_pixel(graphics, j, i, 0x111111);
				j++;
			}
			i++;
		}
		i += x;
	}
}

void	draw_grid(t_graphics *graphics, int x)
{
	ft_bzero(graphics->addr, WIDTH * HEIGHT * 4);
	horizontal(graphics, x);
	vertical(graphics, x);
}
