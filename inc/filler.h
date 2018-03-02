/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 20:26:31 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/03 20:26:33 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
** p1 - O
** p2 - X
*/
# define X		'X'
# define O		'O'
# define FD		fd
# define STDI	0

typedef struct s_sqr	t_sqr;
typedef struct s_stuff	t_stuff;

struct	s_sqr
{
	int		rows;
	int		columns;
	char	**sqr;
};

struct	s_stuff
{
	char	me;
	char	enemy;
	t_sqr	*plateau;
	t_sqr	*(*read_plateau)(char *, int);
	t_sqr	*piece;
	t_sqr	*(*read_piece)(int);
	void	(*insert_piece)(t_stuff *);
	void	(*destructor)(t_sqr **);
	int		i;
	int		j;
	int		len;
	void	(*set_i_j)(t_stuff *);
};
t_sqr	*read_plateau(char *str, int fd);
t_sqr	*read_piece(int fd);
void	insert_piece(t_stuff *instance);
void	set_i_j(t_stuff *instance);
void	destructor(t_sqr **sqr);
int		wave(t_sqr *sqr, int i, int j);
void	putsqr(t_sqr *plateau, char me, char enemy);

/*
** *********************************** Lists ***********************************
*/

typedef struct s_list	t_list;
struct	s_list
{
	t_sqr	*plateau;
	int		evaluation;
	int		i;
	int		j;
	t_list	*next;
};
t_list	*ft_lstnew(t_sqr const *plateau, int evaluation);
//void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
//void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstadd(t_list **head, t_list *lst);

#endif
