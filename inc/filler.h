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
# define X	'X'
# define O	'O'
# define FD	fd

/*
** ********************************** Plateau **********************************
*/

typedef struct s_sqr	t_sqr;
struct	s_sqr
{
	int		rows;
	int		columns;
	char	**sqr;
	int		evaluation;
	char	**(*read)(t_sqr *, int);
	t_sqr	*(*sqrdup)(t_sqr *);
	void	(*set_evaluation)(t_sqr *, char);
	void	(*destructor)(t_sqr *);
};
t_sqr	piece_init(int fd);
t_sqr	plateau_init(int fd);
char	**piece_read(t_sqr *piece, int fd);
char	**plateau_read(t_sqr *plateau, int fd);
t_sqr	*sqrdup(t_sqr *sqr);
void	set_evaluation(t_sqr *sqr, char me);
void	desturctor(t_sqr *sqr);

/*
** *********************************** Piece ***********************************
*/

typedef struct s_stuff	t_stuff;
struct	s_stuff
{
	char	me;
	t_sqr	plateau;
	t_sqr	piece;
	char	**(*insert_piece)(t_stuff *);
};
char	**insert_piece(t_stuff *instance);

/*
** *********************************** Lists ***********************************
*/

typedef struct s_list	t_list;
struct	s_list
{
	t_sqr	*plateau;
	int		evaluation;
	t_list	*next;
};
t_list	*ft_lstnew(t_sqr const *plateau, int evaluation);
//void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
//void	ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void	ft_lstadd(t_list **head, t_list *lst);

#endif
