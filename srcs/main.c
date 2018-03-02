/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:05:48 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/03 19:33:46 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "get_next_line.h"
#include "libft.h"
/* TMP */
#include <fcntl.h>
#include <zconf.h>

static t_stuff	*stuff_init(int fd)
{
	t_stuff	*stuff;
	char	*line;

	get_next_line(fd, &line);
	stuff = (t_stuff *)malloc(sizeof(t_stuff));
	stuff->me = (char)(line[10] == '1' ? 'O' : 'X');
	stuff->enemy = (char)(line[10] == '1' ? 'X' : 'O');
	ft_strdel(&line);
	stuff->read_plateau = read_plateau;
	stuff->read_piece = read_piece;
	stuff->insert_piece = insert_piece;
	stuff->destructor = destructor;
	stuff->i = 0;
	stuff->j = 0;
	stuff->len = 0;
	stuff->set_i_j = set_i_j;
	return (stuff);
}

int				main(int argc, char *argv[])
{
	t_stuff	*instance;
	char	*line;
	int		file;
	int		fd;

	file = open("output", O_WRONLY | O_TRUNC);
	fd = open(argv[1], O_RDONLY);
	instance = stuff_init(fd);
	while (get_next_line(fd, &line) == 1)
	{
		instance->plateau = instance->read_plateau(line, fd);
		ft_strdel(&line);
		instance->piece = instance->read_piece(fd);
		instance->insert_piece(instance);
		instance->destructor(&instance->plateau);
		instance->destructor(&instance->piece);
	}
	close(fd);
	close(file);
	return (0);
}

// ./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
