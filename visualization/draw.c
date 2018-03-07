/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:47:24 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:28 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "visualization.h"
#include "color.h"

void	fill_rectangle(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	int	i;
	int	j;

	i = rect->y;
	while (i < rect->y + rect->w)
	{
		j = rect->x;
		while (j < rect->x + rect->w)
		{
			graphics->put_pixel(graphics, i, j, color);
			j++;
		}
		i++;
	}
}

void	draw(t_graphics *graphics, t_stuff *instance, int x)
{
	t_rect	rect;
	int		i;
	int		j;

	rect.w = x;
	i = 0;
	while (i < instance->plateau->rows)
	{
		j = 0;
		while (j < instance->plateau->columns)
		{
			rect.y = i * (int)rint(x * 1.1);
			rect.x = j * (int)rint(x * 1.1);
			if (instance->plateau->sqr[i][j] == 'X')
				draw_old_x(graphics, &rect, GREEN);
			else if (instance->plateau->sqr[i][j] == 'O')
				draw_old_o(graphics, &rect, RED);
			else if (instance->plateau->sqr[i][j] == 'x')
				draw_new_x(graphics, &rect, GREEN);
			else if (instance->plateau->sqr[i][j] == 'o')
				draw_new_o(graphics, &rect, RED);
			j++;
		}
		i++;
	}
}
