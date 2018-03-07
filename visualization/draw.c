//
// Created by Kyrylo Hrecheniuk on 3/5/18.
//

#include <math.h>
#include "visualization.h"
#include "color.h"

void	draw_rectangle(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	int	i;
	int	j;

	i = rect->x;
	while (i < rect->x + rect->w)
	{
		graphics->put_pixel(graphics, rect->y, i, color);
		graphics->put_pixel(graphics, rect->y + rect->h - 1, i, color);
		i++;
	}
	i = rect->y;
	while (i < rect->y + rect->h)
	{
		graphics->put_pixel(graphics, i, rect->x, color);
		graphics->put_pixel(graphics, i, rect->x + rect->w - 1, color);
		i++;
	}
}

void	fill_rectangle(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	int	i;
	int	j;

	i = rect->y;
	while (i < rect->y + rect->h)
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

void	draw(t_graphics *graphics, t_stuff *instance)
{
	t_rect	rect;
	int		i;
	int		j;

	rect.w = X;
	rect.h = X;
	i = 0;
	while (i < instance->plateau->rows)
	{
		j = 0;
		while (j < instance->plateau->columns)
		{
			rect.y = i * (int)rint(X * 1.1);
			rect.x = j * (int)rint(X * 1.1);
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
