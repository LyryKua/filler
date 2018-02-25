/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 19:48:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/14 19:48:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "libft.h"

t_sqr	plateau_init(int fd)
{
	t_sqr		plateau;
	char		*line;

	get_next_line(fd, &line);
	plateau.rows = ft_atoi(line + 8);
	plateau.columns = ft_atoi(ft_strchr(line + 8, ' '));
	plateau.sqr = NULL;
	plateau.read = plateau_read;
	plateau.sqrdup = sqrdup;
	plateau.destructor = desturctor;
	ft_strdel(&line);
	return (plateau);
}

t_sqr	piece_init(int fd)
{
	t_sqr	piece;
	char		*line;

	get_next_line(fd, &line);
	piece.rows = ft_atoi(line + 6);
	piece.columns = ft_atoi(ft_strchr(line + 6, ' '));
	piece.sqr = NULL;
	piece.read = piece_read;
	piece.sqrdup = sqrdup;
	piece.destructor = desturctor;
	ft_strdel(&line);
	return (piece);
}

char	**plateau_read(t_sqr *plateau, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	get_next_line(fd, &line);
	ft_strdel(&line);
	if (plateau->sqr == NULL)
	{
		plateau->sqr = (char **)malloc(sizeof(char *) * plateau->rows);
		i = 0;
		while (i < plateau->rows)
			plateau->sqr[i++] = NULL;
	}
	i = 0;
	while (i < plateau->rows)
	{
		get_next_line(fd, &line);
		tmp = ft_strsub(line, 4, (size_t)plateau->columns);
		ft_strdel(&plateau->sqr[i]);
		plateau->sqr[i] = tmp;
		ft_strdel(&line);
		i++;
	}
	return (plateau->sqr);
}

char	**piece_read(t_sqr *piece, int fd)
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

t_sqr	*sqrdup(t_sqr *sqr)
{
	t_sqr	*new;
	size_t	i;

	new = (t_sqr *)malloc(sizeof(t_sqr));
	new->rows = sqr->rows;
	new->columns = sqr->columns;
	new->sqr = (char **)malloc(new->rows * sizeof(char *));
	i = 0;
	while (i < new->rows)
	{
		new->sqr[i] = ft_strdup(sqr->sqr[i]);
		i++;
	}
	new->read = sqr->read;
	new->sqrdup = sqr->sqrdup;
	new->destructor = sqr->destructor;
	return (new);
}

void	desturctor(t_sqr *sqr)
{
	int	i;

	i = 0;
	while (i < sqr->rows)
		ft_strdel(&sqr->sqr[i++]);
	free(sqr->sqr);
}