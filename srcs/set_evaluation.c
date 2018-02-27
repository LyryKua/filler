//
// Created by Kyrylo Hrecheniuk on 2/25/18.
//

#include "filler.h"
#include "libft.h"

static int	compute_taxicab_len(int i, int j, int y, int x)
{
	return (ft_abs(i - y) + ft_abs(j - x));
}

static int	compute_length(t_sqr *sqr, int i, int j, char me)
{
	int	len_me;
	int	len_enemy;
	int	y;
	int	x;

//	find_me(sqr, i, j, me);
	len_me = compute_taxicab_len(i, j, y, x);
	len_enemy = 1;
	return (len_me < len_enemy ? -1 : 1);
}

void	set_evaluation(t_sqr *sqr, char me)
{
	int	i;
	int	j;

	i = 0;
	while (i < sqr->rows)
	{
		j = 0;
		while (j < sqr->columns)
		{
			sqr->evaluation += compute_length(sqr, i, j, me);
			j++;
		}
		i++;
	}
}