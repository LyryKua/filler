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
#include <stdlib.h>
#include "libft.h"
#include "visualization.h"

int	main(int argc, char *argv[])
{
	t_stuff		*instance;
	char		*line;
	int			i;
	int			fd;
//	t_graphics	*graphics;
//	t_point		point;

//	graphics = init_graphics(442, 542, "test");
//	point.x = 42;
//	point.y = 42;
//	point.color = GREEN;
//	while (point.x < 142)
//	{
//		graphics->put_pixel(graphics, &point);
//		point.x++;
//	}
//	mlx_put_image_to_window(graphics->mlx, graphics->win, graphics->img, 0, 0);
//	mlx_loop(graphics->mlx);
//	graphics->destructor(&graphics);
//	fd = open(argv[1], O_RDONLY);
//	i = 0;
//	while (i++ < 9 & get_next_line(fd, &line) == 1)
//		ft_strdel(&line);
//	instance = init_stuff();
//	get_next_line(fd, &line);
//	ft_strdel(&line);
//	instance->destructor(&instance->plateau);
//	instance->destructor(&instance->piece);
//	free(instance);
//	close(fd);
	while (get_next_line(STDIN_FILENO, &line) >= 0)
	{
		if (ft_isalpha(line[0]))
			ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
