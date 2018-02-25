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

//void	putsqr(t_stuff *instance, int i, int j)
//{
//	int	x;
//	int	y;
//	bool	flag;
//
//	flag = false;
//	y = i;
//	for (int k = 0; k < instance->plateau.rows; ++k)
//	{
//		x = j;
//		for (int l = 0; l < instance->plateau.columns; ++l)
//		{
//			if (k == y && l == x && x - j < instance->piece.columns && y - i < instance->piece.rows)
//			{
//				ft_putchar(instance->piece.sqr[y - i][x - j]);
//				flag = true;
//				x++;
//			}
//			else
//				ft_putchar(instance->plateau.sqr[k][l]);
//		}
//		if (flag == true)
//			y++;
//		ft_putchar('\n');
//	}
//	ft_printf("***********************\n");
//}
void	putsqr(t_sqr *plateau, int i, int j)
{
	int	x;
	int	y;
	bool	flag;

	flag = false;
	y = i;
	for (int k = 0; k < plateau->rows; ++k)
	{
		ft_putendl(plateau->sqr[k]);
	}
	ft_printf("***********************\n");
}

t_list	*piece_to_plateau(t_stuff *instance, int y, int x)
{
	t_list	*new;
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
	new = ft_lstnew(plato, 42);
	return (new);
}

void	try_insert(t_stuff *instance, int i, int j, t_list **head)
{
	int		x;
	int		y;
	int		match;
	t_list	*new;

	match = 0;
	y = 0;
	while (y < instance->piece.rows)
	{
		x = 0;
		while (x < instance->piece.columns)
		{
			if (instance->piece.sqr[y][x] == '*'
						&& instance->plateau.sqr[i + y][j + x] == instance->me)
				match++;
			x++;
		}
		y++;
	}
	if (match == 1)
	{
		new = piece_to_plateau(instance, i, j);
		ft_lstadd(head, new);
	}
}

char	**insert_piece(t_stuff *instance)
{
	int		i;
	int		j;
	t_list	*head;

	head = NULL;
	i = 0;
	while (i < instance->plateau.rows - instance->piece.rows)
	{
		j = 0;
		while (j < instance->plateau.columns - instance->piece.columns)
		{
			try_insert(instance, i, j, &head);
			j++;
		}
		i++;
	}
	while (head != NULL)
	{
		putsqr(head->plateau, 0 , 0);
		ft_printf("e = %d\n", head->evaluation);
		head = head->next;
	}
	return (instance->plateau.sqr);
}

int		main(int argc, char *argv[])
{
	t_stuff	instance;
	int		fd;
	char	*line;
	t_sqr	*plato;
	t_list	*lst;
	t_list	*tmp;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	instance.me = (char)(line[10] == '1' ? O : X);
	ft_strdel(&line);
	instance.plateau = plateau_init(fd);
	instance.plateau.read(&instance.plateau, fd);
	instance.piece = piece_init(fd);
	instance.piece.read(&instance.piece, fd);
	instance.insert_piece = insert_piece;
//	plato = instance.plateau.sqrdup(&instance.plateau);
//	instance.plateau.sqr[1][1] = '*';
//	putsqr(&instance.plateau, 0, 0);
//	putsqr(plato, 0, 0);
	instance.insert_piece(&instance);
	close(fd);
	return (0);
}

// ./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
