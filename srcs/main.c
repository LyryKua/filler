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

#define N	0
#define M	0

/*
t_sqr	*piece_to_plateau(t_stuff *instance, int y, int x)
{
	t_sqr	*plato;
	int		i;
	int		j;

	plato = instance->plateau.sqrdup(&instance->plateau);
	i = 0;
	while (i < instance->piece.rows)
	{
		j = 0;
		while (j < instance->piece.columns)
		{
			if (instance->piece.sqr[i][j] == '*')
				plato->sqr[y + i][x + j] = instance->me;
			j++;
		}
		i++;
	}
	plato->set_evaluation(instance);
	return (plato);
}
*/

int		main(int argc, char *argv[])
{
	t_stuff	instance;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	instance.me = (char)(line[10] == '1' ? 'O' : 'X');
	ft_strdel(&line);
	instance.plateau = plateau_init(fd);
	instance.plateau->read(instance.plateau, fd);
	instance.piece = piece_init();
	instance.piece->read(instance.piece, fd);
	instance.insert_piece = insert_piece;
	instance.i = 0;
	instance.j = 0;
	instance.insert_piece(&instance);
	while (get_next_line(fd, &line) == 1)
	{
		ft_strdel(&line);
		instance.plateau->read(instance.plateau, fd);
		instance.piece->read(instance.piece, fd);
		instance.insert_piece(&instance);
	}
	close(fd);
	return (0);
}

// ./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
