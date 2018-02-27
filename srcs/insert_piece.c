#include "filler.h"
#include "libft.h"
#include "ft_printf.h"

t_sqr	*piece_to_plateau(t_stuff *instance, int i, int j)
{
	t_sqr	*plateau;
	int		y;
	int		x;

	plateau = instance->plateau->sqrdup(instance->plateau);
	y = 0;
	while (y < instance->piece->rows)
	{
		x = 0;
		while (x < instance->piece->columns)
		{
			if (instance->piece->sqr[y][x] == '*')
				plateau->sqr[i + y][j + x] = (char)ft_tolower(instance->me);
			x++;
		}
		y++;
	}
	putsqr(plateau);
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
			if (instance->piece->sqr[y][x] == '*'
						&& instance->plateau->sqr[i + y][j + x] == instance->me)
				match++;
			x++;
		}
		y++;
	}
	return (match);
}

static void			try_insert(t_stuff *instance, int i, int j)
{
	t_sqr	*tmp;

	if (count_match(instance, i, j) == 1)
	{
		tmp = piece_to_plateau(instance, i, j);
		tmp->set_evaluation(tmp, instance->me);
		if (tmp->evaluation > instance->plateau->evaluation)
		{
			instance->plateau->destructor(instance->plateau);
			instance->plateau = tmp;
			instance->i = i;
			instance->j = j;
		}
	}
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
			try_insert(instance, i, j);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", instance->i, instance->j);
	ft_putendl("******************");
}