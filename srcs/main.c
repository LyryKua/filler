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

void	putsqr(t_stuff *instance, int i, int j)
{
	int	x, y;
	x = j;
	y = i;
	for (int k = 0; k < instance->plateau.rows; ++k)
	{
		for (int l = 0; l < instance->plateau.columns; ++l)
		{
			if (k == y && l == x)
			{
				ft_putchar(instance->piece.sqr[y - i][x - j]);
				y++;
				x++;
			}
			else
				ft_putchar(instance->plateau.sqr[k][l]);
		}
		ft_putchar('\n');
	}
	ft_printf("***********************\n");
}

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": input_file", 2);
	exit(1);
}

bool	try_insert(t_stuff *instance, int i, int j)
{
	int	x;
	int	y;
	int	match;

	x = 0;
	match = 0;
	y = 0;
	while (y < instance->piece.rows)
	{
		x = 0;
		while (x < instance->piece.columns)
		{
			if (instance->piece.sqr[y][x] == '*' && instance->plateau.sqr[i + y][j + x] == instance->me)
				match++;
			x++;
		}
		y++;
	}
	if (match == 1)
	{
		putsqr(instance, i + y, j + x);
	}
	return (false);
}

char	**insert_piece(t_stuff *instance)
{
	int		i;
	int		j;
	bool	end;

	end = false;
	i = 0;
	while (i < instance->plateau.rows - instance->piece.rows)
	{
		j = 0;
		while (j < instance->plateau.columns - instance->piece.columns)
		{
			if (try_insert(instance, i, j))
			{
				end = true;
				break ;
			}
			j++;
		}
		if (end == true)
			break ;
		i++;
	}
	return (instance->plateau.sqr);
}

int		main(int argc, char *argv[])
{
	t_stuff	instance;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	instance.me = (char)(line[10] == '1' ? O : X);
	ft_strdel(&line);
	instance.plateau = plateau_init(fd);
	instance.plateau.read(&instance.plateau, fd);
	instance.piece = piece_init(fd);
	instance.piece.read(&instance.piece, fd);
	instance.insert_piece = insert_piece;
	instance.insert_piece(&instance);
	close(fd);
	return (0);
}

//./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
