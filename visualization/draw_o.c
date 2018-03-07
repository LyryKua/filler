/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:02:44 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/06 14:02:46 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"
#include "visualization.h"

static void	draw_line(t_graphics *graphics, t_point start, t_point end)
{
	int	i;

	while (start.y <= end.y)
	{
		i = start.x;
		while (i <= end.x)
		{
			graphics->put_pixel(graphics, start.y, i, start.color);
			i++;
		}
		start.y++;
	}
}

static void	draw_part_o(t_graphics *graphics, t_point start, t_point end,
																	int finish)
{
	while (start.y <= finish)
	{
		draw_line(graphics, start, end);
		start.y++;
		end.y++;
	}
}

void		draw_old_o(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	t_point	start;
	t_point	end;
	int		finish;

	fill_rectangle(graphics, rect, color);
	draw_old_x(graphics, rect, color);
	start.color = BLACK;
	start.x = rect->x + (int)rint(rect->w * 0.35);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.65);
	end.y = start.y;
	finish = rect->y + (int)rint(rect->w * 0.85);
	draw_part_o(graphics, start, end, finish);
	start.x = rect->x + (int)rint(rect->w * 0.15);
	start.y = rect->y + (int)rint(rect->w * 0.35);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.35);
	finish = rect->y + (int)rint(rect->w * 0.65);
	draw_part_o(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_o(graphics, start, end, finish);
}

void		draw_new_o(t_graphics *graphics, t_rect *rect, unsigned int color)
{
	t_point	start;
	t_point	end;
	int		finish;

	draw_new_x(graphics, rect, color);
	start.color = color;
	start.x = rect->x + (int)rint(rect->w * 0.35);
	start.y = rect->y + (int)rint(rect->w * 0.15);
	end.x = rect->x + (int)rint(rect->w * 0.65);
	end.y = start.y;
	finish = rect->y + (int)rint(rect->w * 0.85);
	draw_part_o(graphics, start, end, finish);
	start.x = rect->x + (int)rint(rect->w * 0.15);
	start.y = rect->y + (int)rint(rect->w * 0.35);
	end.x = rect->x + (int)rint(rect->w * 0.85);
	end.y = rect->y + (int)rint(rect->w * 0.35);
	finish = rect->y + (int)rint(rect->w * 0.65);
	draw_part_o(graphics, start, end, finish);
	start.x++;
	finish++;
	draw_part_o(graphics, start, end, finish);
}
