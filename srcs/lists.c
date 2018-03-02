//
// Created by Kyrylo Hrecheniuk on 2/24/18.
//

#include <stdlib.h>
#include "filler.h"

t_list	*ft_lstnew(t_sqr const *plateau, int evaluation)
{
	t_list	*lstnew;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (plateau != NULL)
	{
		lstnew->plateau = plateau->sqrdup((t_sqr *)plateau);
		lstnew->evaluation = evaluation;
	}
	else
		lstnew->plateau = NULL;
	lstnew->next = NULL;
	return (lstnew);
}

void	ft_lstadd(t_list **head, t_list *lst)
{
	if (head && lst)
	{
		lst->next = *head;
		*head = lst;
	}
}