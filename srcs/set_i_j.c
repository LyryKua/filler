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
#include <limits.h>
#include "filler.h"
#include "ft_printf.h"
#include "libft.h"

t_sqr				*read_plateau(char *str)
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

t_sqr				*read_piece(void)
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

static unsigned int	count_match(t_stuff *instance, int i, int j)
{
	unsigned int	match;
	int				y;
	int				x;

	match = 0;
	y = 0;
	while (y < instance->piece->rows)
	{
		x = 0;
		while (x < instance->piece->columns)
		{
			if (instance->piece->sqr[y][x] == '*')
			{
				if (instance->plateau->sqr[i + y][j + x] == instance->enemy)
					return (0);
				else if (instance->plateau->sqr[i + y][j + x] == instance->me)
					match++;
			}
			x++;
		}
		y++;
	}
	return (match);
}

void				insert_piece(t_stuff *instance)
{
	int		i;
	int		j;

	instance->i = 0;
	instance->j = 0;
	instance->len = INT_MAX;
	i = 0;
	while (i <= instance->plateau->rows - instance->piece->rows)
	{
		j = 0;
		while (j <= instance->plateau->columns - instance->piece->columns)
		{
			if (count_match(instance, i, j) == 1)
				instance->set_i_j(instance, i, j);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", instance->i, instance->j);
}

void				destructor(t_sqr **sqr)
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
