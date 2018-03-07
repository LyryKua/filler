//
// Created by Kyrylo Hrecheniuk on 2/27/18.
//

#include "visualization.h"
#include "libft.h"

void	putsqr(t_sqr *plateau)
{
	for (int i = 0; i < plateau->rows; ++i)
	{
		for (int j = 0; j < plateau->columns; ++j)
		{
			if (plateau->sqr[i][j] == 'X')
			{
				ft_putstr("\033[31m");
				ft_putchar(plateau->sqr[i][j]);
				ft_putstr("\033[0m");
			}
			else if (plateau->sqr[i][j] == 'O')
			{
				ft_putstr("\033[32m");
				ft_putchar(plateau->sqr[i][j]);
				ft_putstr("\033[0m");
			}
			else if (plateau->sqr[i][j] == 'x')
			{
				ft_putstr("\033[91m");
				ft_putchar(plateau->sqr[i][j]);
				ft_putstr("\033[0m");
			}
			else if (plateau->sqr[i][j] == 'o')
			{
				ft_putstr("\033[92m");
				ft_putchar(plateau->sqr[i][j]);
				ft_putstr("\033[0m");
			}
			else
				ft_putchar(plateau->sqr[i][j]);
		}
		ft_putchar('\n');
	}
	for (int i = 0; i < plateau->columns + 2; ++i)
		ft_putchar('-');
	ft_putchar('\n');
}