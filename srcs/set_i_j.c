//
// Created by Kyrylo Hrecheniuk on 2/25/18.
//

#include "filler.h"

void	set_i_j(t_stuff *instance, int i , int j)
{
	int	y;
	int	x;
	int	len;

	y = 0;
//	printf("test\n");
	while (y < instance->plateau->rows)
	{
		x = 0;
		while (x < instance->plateau->columns)
		{
			if (instance->plateau->sqr[y][x] == instance->enemy)
			{
				len = (y - i) * (y - i) + (x - j) * (x - j);
				if (len < instance->len)
				{
					instance->i = i;
					instance->j = j;
					instance->len = len;
				}
			}
			x++;
		}
		y++;
	}
}