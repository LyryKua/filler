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
#include <unistd.h>
#include "visualization.h"
#include "libft.h"

t_sqr	*read_plateau(char *str)
{
	t_sqr	*plateau;
	char	*line;
	int		i;

	plateau = (t_sqr *)malloc(sizeof(t_sqr));
	plateau->rows = ft_atoi(ft_strchr(str, ' '));
	plateau->columns = ft_atoi(ft_strrchr(str, ' '));
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	plateau->sqr = (char **)malloc(plateau->rows * sizeof(char *));
	i = 0;
	while (i < plateau->rows)
	{
		get_next_line(STDIN_FILENO, &line);
		plateau->sqr[i++] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
	}
	return (plateau);
}

t_sqr	*read_piece(void)
{
	t_sqr	*piece;
	char	*line;
	int		i;

	piece = (t_sqr *)malloc(sizeof(t_sqr));
	get_next_line(STDIN_FILENO, &line);
	piece->rows = ft_atoi(ft_strchr(line, ' '));
	piece->columns = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	piece->sqr = (char **)malloc(piece->rows * sizeof(char *));
	i = 0;
	while (i < piece->rows)
	{
		get_next_line(STDIN_FILENO, &line);
		piece->sqr[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	return (piece);
}

void	destructor_stuff(t_sqr **sqr)
{
	int	i;

	if (sqr)
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
	stuff->piece = NULL;
	stuff->read_plateau = read_plateau;
	stuff->read_piece = read_piece;
	stuff->destructor = destructor_stuff;
	return (stuff);
}