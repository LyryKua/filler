/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:40:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 20:40:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"

t_piece	piece_init(int fd)
{
	t_piece	piece;
	char		*line;

	get_next_line(fd, &line);
	piece.rows = ft_atoi(line + 6);
	piece.columns = ft_atoi(ft_strchr(line + 6, ' '));
	piece.sqr = NULL;
	piece.read = piece_read;
	piece.destructor = piece_desturctor;
	ft_strdel(&line);
	return (piece);
}

char		**piece_read(t_piece *piece, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	if (piece->sqr == NULL)
	{
		piece->sqr = (char **)malloc(sizeof(char *) * piece->rows);
		i = 0;
		while (i < piece->rows)
			piece->sqr[i++] = NULL;
	}
	i = 0;
	while (i < piece->rows)
	{
		get_next_line(fd, &line);
		tmp = line;
		ft_strdel(&piece->sqr[i]);
		piece->sqr[i] = tmp;
		i++;
	}
	return (piece->sqr);
}

void		piece_desturctor(t_piece *piece)
{
	int	i;

	i = 0;
	while (i < piece->rows)
		ft_strdel(&piece->sqr[i++]);
	free(piece->sqr);
}
