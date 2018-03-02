//
// Created by Kyrylo Hrecheniuk on 2/25/18.
//

#include <limits.h>
#include "filler.h"
#include "libft.h"

static int	compute_taxicab_len(int i, int j, int y, int x)
{
	return (ft_abs(i - y) + ft_abs(j - x));
}

static int	compute_length(t_sqr *sqr, int i, int j, char me)
{
	int		len_me;
	int		len_enemy;
	int		tmp;
	int		y;
	int		x;
	int		w;
	char	enemy;

//	find_me(sqr, i, j, me);
	enemy = (char)(me == 'X' ? 'O' : 'X');
	len_me = INT_MAX;
	len_enemy = INT_MAX;
	w = wave(sqr, i, j);
	y = i - w;
	while (y <= i + w)
	{
		x = j - w;
		while (x <= j + w)
		{
			if (y >= 0 && y < sqr->rows && x >= 0 && x <= sqr->columns)
			{
				if (sqr->sqr[y][x] == me)
				{
					tmp = ft_abs(i - y) + ft_abs(j - x);
					if (tmp < len_me)
						len_me = tmp;
				}
				else if (sqr->sqr[y][x] == enemy)
				{
					tmp = ft_abs(i - y) + ft_abs(j - x);
					if (tmp < len_enemy)
						len_enemy = tmp;
				}
			}
			x++;
		}
		y++;
	}
	if (len_me > len_enemy)
		return (1);
	else if (len_me < len_enemy)
		return (-1);
	return (0);
}

int		get_evaluation(t_sqr *sqr, char me)
{
	int	eval;
	int	i;
	int	j;

	eval = 0;
	i = 0;
	while (i < sqr->rows)
	{
		j = 0;
		while (j < sqr->columns)
		{
			if (sqr->sqr[i][j] == '.')
				eval += compute_length(sqr, i, j, me);
			j++;
		}
		i++;
	}
	return (eval);
}