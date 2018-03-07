/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:48:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 19:48:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>
#include "visualization.h"
#include "get_next_line.h"

t_sqr	*read_plateau(char *str, int fd)
{
	t_sqr	*plateau;
	char	*line;
	int		i;

	plateau = (t_sqr *)malloc(sizeof(t_sqr));
	plateau->rows = ft_atoi(ft_strchr(str, ' '));
	plateau->columns = ft_atoi(ft_strrchr(str, ' '));
	get_next_line(fd, &line);
	ft_strdel(&line);
	plateau->sqr = (char **)malloc(plateau->rows * sizeof(char *));
	i = 0;
	while (i < plateau->rows)
	{
		get_next_line(fd, &line);
		plateau->sqr[i++] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
	}
	return (plateau);
}

void	destructor_stuff(t_sqr **sqr)
{
	int	i;

	if (*sqr)
	{
		i = 0;
		while (i < (*sqr)->rows)
			ft_strdel(&(*sqr)->sqr[i++]);
		free((*sqr)->sqr);
		(*sqr)->sqr = NULL;
		free(*sqr);
		*sqr = NULL;
	}
}

t_stuff	*init_stuff()
{
	t_stuff	*stuff;

	stuff = (t_stuff *)malloc(sizeof(t_stuff));
	stuff->plateau = NULL;
	stuff->read_plateau = read_plateau;
	stuff->destructor = destructor_stuff;
	return (stuff);
}