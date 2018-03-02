#include "filler.h"
#include "libft.h"
#include "ft_printf.h"

t_sqr	*piece_to_plateau(t_stuff *instance, t_sqr *plateau, int i, int j)
{
	int		y;
	int		x;
	char	enemy;

	enemy = (char)(instance->me == 'X' ? 'O' : 'X');
	y = 0;
	while (y < instance->piece->rows)
	{
		x = 0;
		while (x < instance->piece->columns)
		{
			if (instance->piece->sqr[y][x] == '*' && ft_toupper(plateau->sqr[i + y][j + x]) != enemy)
				plateau->sqr[i + y][j + x] = (char)ft_tolower(instance->me);
			x++;
		}
		y++;
	}
	return (plateau);
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

	i = 0;
	while (i <= instance->plateau->rows - instance->piece->rows)
	{
		j = 0;
		while (j <= instance->plateau->columns - instance->piece->columns)
		{
			if (count_match(instance, i, j) == 1)
				instance->set_i_j(instance);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", instance->i, instance->j);
	ft_printf("len = %d\n", instance->len);
}