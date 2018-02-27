/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wave.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 13:43:36 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/27 13:43:37 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "filler.h"
#include "libft.h"

static bool	vertical(t_sqr *sqr, int i, int j, int w)
{
	int		y;
	bool	flag;

	flag = false;
	y = i - w;
	while (y <= i + w)
	{
		if (y >= 0 && y < sqr->rows)
		{
			if (j - w >= 0)
				flag = ft_isalpha(sqr->sqr[y][j - w]) ? true : flag;
			if (j + w < sqr->columns)
				flag = ft_isalpha(sqr->sqr[y][j + w]) ? true : flag;
		}
		y++;
	}
	return (flag);
}

static bool	horizontal(t_sqr *sqr, int i, int j, int w)
{
	bool	flag;
	int		x;

	flag = false;
	x = j - w;
	while (x <= j + w)
	{
		if (x >= 0 && x < sqr->columns)
		{
			if (i - w >= 0)
				flag = ft_isalpha(sqr->sqr[i - w][x]) ? true : flag;
			if (i + w < sqr->rows)
				flag = ft_isalpha(sqr->sqr[i + w][x]) ? true : flag;
		}
		x++;
	}
	return (flag);
}

int			wave(t_sqr *sqr, int i, int j)
{
	int		w;
	bool	flag;

	flag = true;
	w = 1;
	while (flag == true)
	{
		flag = vertical(sqr, i, j, w) ? false : flag;
		flag = horizontal(sqr, i, j, w) ? false : flag;
		w += flag == true ? 1 : 0;
	}
	return (w);
}
