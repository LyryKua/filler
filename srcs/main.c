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
#include <fcntl.h>
#include <zconf.h>
#include <errno.h>
#include <stdio.h>
#include "filler.h"
#include "ft_printf.h"
#include "libft.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": input_file", 2);
	exit(1);
}

int		main(int argc, char *argv[])
{
	t_stuff	instance;
	t_sqr	plateau;
	t_sqr	piece;
	int		fd;
	char	*line;

	if (argc != 2)
		error_exit("usage");
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_strdel(&line);
	plateau = plateau_init(fd);
	plateau.read(&plateau, fd);
	plateau.read(&plateau, fd);
	for (int i = 0; i < plateau.rows; ++i)
		ft_putendl(plateau.sqr[i]);
	ft_putendl("***************************");
	plateau.destructor(&plateau);

	piece = piece_init(fd);
	piece.read(&piece, fd);
	piece.read(&piece, fd);
	for (int i = 0; i < piece.rows; ++i)
		ft_putendl(piece.sqr[i]);
	ft_putendl("***************************");
	piece.destructor(&piece);
	while (42);
	return (0);
}
//./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr