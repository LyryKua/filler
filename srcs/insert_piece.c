#include <stdlib.h>
#include <limits.h>
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
	char			enemy;
	int				y;
	int				x;

	enemy = (char)(instance->me == 'X' ? 'O' : 'X');
	match = 0;
	y = 0;
	while (y < instance->piece->rows)
	{
		x = 0;
		while (x < instance->piece->columns)
		{
			if (instance->piece->sqr[y][x] == '*')
			{
				if (ft_toupper(instance->plateau->sqr[i + y][j + x]) == enemy)
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

static void			try_insert(t_stuff *instance, t_list **head, int i, int j)
{
	t_list	*tmp;

	tmp = ft_lstnew(instance->plateau, 0);
	tmp->plateau = piece_to_plateau(instance, tmp->plateau, i, j);
	tmp->evaluation = get_evaluation(tmp->plateau, instance->me);
	tmp->i = i;
	tmp->j = j;
	ft_lstadd(head, tmp);
}

void				insert_piece(t_stuff *instance)
{
	t_list	*head;
	t_list	*tmp;
	int		i;
	int		j;

	head = NULL;
	i = 0;
	while (i <= instance->plateau->rows - instance->piece->rows)
	{
		j = 0;
		while (j <= instance->plateau->columns - instance->piece->columns)
		{
			if (count_match(instance, i, j) == 1)
				try_insert(instance, &head, i, j);
			j++;
		}
		i++;
	}
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->evaluation > instance->plateau->evaluation)
		{
			instance->plateau->destructor(instance->plateau);
			instance->plateau = tmp->plateau;
			instance->plateau->evaluation = tmp->evaluation;
			instance->i = tmp->i;
			instance->j = tmp->j;
		}
		tmp = tmp->next;
	}
	ft_printf("%d %d\n", instance->i, instance->j);
}