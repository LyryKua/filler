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
#include <unistd.h>
#include "filler.h"
#include "get_next_line.h"
#include "libft.h"

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
	stuff->set_i_j = set_i_j;
	return (stuff);
}

int				main(void)
{
	t_stuff	*instance;
	char	*line;

	instance = stuff_init(STDIN_FILENO);
	while (get_next_line(STDIN_FILENO, &line) == 1)
	{
		instance->plateau = instance->read_plateau(line);
		ft_strdel(&line);
		instance->piece = instance->read_piece();
		instance->insert_piece(instance);
		instance->destructor(&instance->plateau);
		instance->destructor(&instance->piece);
	}
	free(instance);
	return (0);
}
