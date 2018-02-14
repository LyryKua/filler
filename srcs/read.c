/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:32:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 18:32:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"

t_plateau	*read_plateau(int fd)
{
	t_plateau	*plateau;
	char		*line;
	size_t		i;

	plateau = (t_plateau *)malloc(sizeof(t_plateau));
	get_next_line(fd, &line);
	plateau->rows = ft_atoi(line + 8);
	plateau->columns = ft_atoi(ft_strchr(line + 8, ' '));
	plateau->sqr = (char **)malloc(sizeof(char *) * plateau->rows);
	ft_strdel(&line);
	get_next_line(fd, &line);
	ft_strdel(&line);
	i = 0;
	while (i < plateau->rows)
	{
		get_next_line(fd, &line);
		plateau->sqr[i] = ft_strsub(line, 4, (size_t)plateau->columns);
		ft_strdel(&line);
		i++;
	}
	return (plateau);
}

t_piece		*read_piece(int fd)
{
	t_piece	*piece;
	char	*line;
	int		i;

	piece = (t_piece *)malloc(sizeof(t_piece));
	get_next_line(fd, &line);
	piece->rows = ft_atoi(line + 6);
	piece->columns = ft_atoi(ft_strchr(line + 6, ' '));
	piece->sqr = (char **)malloc(sizeof(char *) * piece->rows);
	ft_strdel(&line);
	i = 0;
	while (i < piece->rows)
	{
		get_next_line(fd, &line);
		piece->sqr[i] = line;
		i++;
	}
	return (piece);
}
