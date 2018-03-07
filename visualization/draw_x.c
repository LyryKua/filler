/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:37 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/06 14:02:40 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "visualization.h"
#include "color.h"

static void	draw_diagonal(t_graphics *graphics, t_point start, t_point end)
{
	while (start.x <= end.x)
		graphics->put_pixel(graphics, start.y++, start.x++, start.color);
}

static void	draw_part_x(t_graphics *graphics, t_point start, t_point end,
																	int finish)
{
	while (start.x >= finish)
	{
		draw_diagonal(graphics, start, end);
		start.x--;
		start.y++;
		end.x--;
		end.y++;
	}
}

void		draw_old_x(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	t_point	start;
	t_point	end;
	int		finish;

	fill_rectangle(graphics, rect, color);
	start.color = BLACK;
	start.x = rect->x + (int)rint(rect->w * 0.65);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.35);
	finish = rect->x + (int)rint(rect->w * 0.15);
	draw_part_x(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_x(graphics, start, end, finish);
	start.x = rect->x + (int)rint(rect->w * 0.35);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.65);
	finish = rect->x + (int)rint(rect->w * 0.15);
	draw_part_x(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_x(graphics, start, end, finish);
}

void		draw_new_x(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	t_point	start;
	t_point	end;
	int		finish;

	start.color = color;
	start.x = rect->x + (int)rint(rect->w * 0.65);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.35);
	finish = rect->x + (int)rint(rect->w * 0.15);
	draw_part_x(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_x(graphics, start, end, finish);
	start.x = rect->x + (int)rint(rect->w * 0.35);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.65);
	finish = rect->x + (int)rint(rect->w * 0.15);
	draw_part_x(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_x(graphics, start, end, finish);
}
