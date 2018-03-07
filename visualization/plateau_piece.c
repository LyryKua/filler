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
#include <libft.h>
#include "visualization.h"

t_sqr	*read_plateau(char *str, int fd)
{
	t_sqr	*plateau;
	char	*line;
	int		i;
	char	*tmp;

	plateau = (t_sqr *)malloc(sizeof(t_sqr));
	if ((tmp = ft_strchr(str, ' ')))
		plateau->rows = ft_atoi(tmp);
	else
		exit(1);
	if ((tmp = ft_strrchr(str, ' ')))
		plateau->columns = ft_atoi(tmp);
	else
		exit(1);
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

t_stuff	*init_stuff(void)
{
	t_stuff	*stuff;

	stuff = (t_stuff *)malloc(sizeof(t_stuff));
	stuff->plateau = NULL;
	stuff->read = read_plateau;
	stuff->destructor = destructor_stuff;
	return (stuff);
}
