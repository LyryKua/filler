/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plateau.c                                          :+:      :+:    :+:   */
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

t_plateau	plateau_init(int fd)
{
	t_plateau	plateau;
	char		*line;

	get_next_line(fd, &line);
	plateau.rows = ft_atoi(line + 8);
	plateau.columns = ft_atoi(ft_strchr(line + 8, ' '));
	plateau.sqr = NULL;
	plateau.read = plateau_read;
	plateau.destructor = plateau_desturctor;
	ft_strdel(&line);
	return (plateau);
}

char		**plateau_read(t_plateau *plateau, int fd)
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

void		plateau_desturctor(t_plateau *plateau)
{
	int	i;

	i = 0;
	while (i < plateau->rows)
		ft_strdel(&plateau->sqr[i++]);
	free(plateau->sqr);
}