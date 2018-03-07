/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:38:00 by khrechen          #+#    #+#             */
/*   Updated: 2017/10/16 16:38:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <zconf.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <printf.h>
#include "key_events.h"
#include "visualization.h"
#include "get_next_line.h"
#include "libft.h"
#include "color.h"

void	draw_grid(t_graphics *graphics)
{
	int	i;
	int	j;
	int	finish;

	ft_bzero(graphics->addr, WIDTH * HEIGHT * 4);
	i = X;
	while (i < graphics->h)
	{
		finish = i + (int)rint(X * 0.1);
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
		i += X;
	}
	i = X;
	while (i < graphics->w)
	{
		finish = i + (int)rint(X * 0.1);
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
		i += X;
	}
}

int		visualization(t_all *param)
{
	char	*line;

	while (get_next_line(param->fd, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			param->instance->plateau = param->instance->read_plateau(line,
																	param->fd);
//			ft_bzero(param->graphics->addr, WIDTH * HEIGHT * 4);
			draw_grid(param->graphics);
			draw(param->graphics, param->instance);
			mlx_put_image_to_window(param->graphics->mlx, param->graphics->win,
													param->graphics->img, 0 ,0);
			param->instance->destructor(&param->instance->plateau);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
//	usleep(600000);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_all	all;
	char	*line;
	int		win_w;
	int		win_h;

	all.fd = open(argv[1], O_RDONLY);
	all.instance = init_stuff();
	while (get_next_line(all.fd, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			all.instance->plateau = all.instance->read_plateau(line, all.fd);
			ft_strdel(&line);
			break;
		}
		ft_strdel(&line);
	}
	win_h = (int)rint(all.instance->plateau->rows * X * 1.1 - X * 0.1);
	win_w = (int)rint(all.instance->plateau->columns * X * 1.1 - X * 0.1);
	all.graphics = init_graphics(win_w, win_h, "MAGIC");
	draw(all.graphics, all.instance);
	all.instance->destructor(&all.instance->plateau);
	mlx_put_image_to_window(all.graphics->mlx, all.graphics->win,
													all.graphics->img, 0 ,0);
	mlx_loop_hook(all.graphics->mlx, visualization, &all);
	mlx_loop(all.graphics->mlx);
	return (0);
}
