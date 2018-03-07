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
#include "key_events.h"
#include "visualization.h"
#include "get_next_line.h"
#include "libft.h"
#include "key_map.h"

static int		close_window(void)
{
	exit(0);
}

static int		esc_exit(int keycode)
{
	if (keycode == ESC)
		close_window();
	return (0);
}

static int		visualization(t_all *param)
{
	char	*line;

	while (get_next_line(param->fd, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			param->instance->plateau = param->instance->read(line, param->fd);
			draw_grid(param->graphics, param->x);
			draw(param->graphics, param->instance, param->x);
			mlx_put_image_to_window(param->graphics->mlx, param->graphics->win,
													param->graphics->img, 0, 0);
			param->instance->destructor(&param->instance->plateau);
			ft_strdel(&line);
			break ;
		}
		if (ft_strstr(line, "=="))
		{
			ft_putendl(line);
			ft_strdel(&line);
			get_next_line(param->fd, &line);
			ft_putendl(line);
		}
		ft_strdel(&line);
	}
	return (0);
}

static t_sqr	*first_read(int fd, t_stuff *instance)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			instance->plateau = instance->read(line, fd);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return (instance->plateau);
}

int				main(void)
{
	t_all	all;
	int		win_w;
	int		win_h;

	all.x = X;
	all.fd = 0;
	all.instance = init_stuff();
	all.instance->plateau = first_read(all.fd, all.instance);
	if (all.instance->plateau->rows * all.x > 1000)
		all.x = 12;
	win_h = (int)rint(all.x * (all.instance->plateau->rows * 1.1 - 0.1));
	win_w = (int)rint(all.x * (all.instance->plateau->columns * 1.1 - 0.1));
	all.graphics = init_graphics(win_w, win_h, "MAGIC");
	draw(all.graphics, all.instance, all.x);
	all.instance->destructor(&all.instance->plateau);
	mlx_put_image_to_window(all.graphics->mlx, all.graphics->win,
													all.graphics->img, 0, 0);
	mlx_key_hook(all.graphics->win, esc_exit, &all);
	mlx_hook(all.graphics->win, DESTROY_NOTIFY, (1L << 17), close_window, NULL);
	mlx_loop_hook(all.graphics->mlx, visualization, &all);
	mlx_loop(all.graphics->mlx);
	return (0);
}
