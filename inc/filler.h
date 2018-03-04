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

#include <printf.h>

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
	t_sqr	*(*read_plateau)(char *, int, int);
	t_sqr	*piece;
	t_sqr	*(*read_piece)(int, int);
	void	(*insert_piece)(t_stuff *);
	void	(*destructor)(t_sqr **);
	int		i;
	int		j;
	int		len;
	void	(*set_i_j)(t_stuff *, int , int);
};
t_sqr	*read_plateau(char *str, int fd, int file);
t_sqr	*read_piece(int fd, int file);
void	insert_piece(t_stuff *instance);
void	set_i_j(t_stuff *instance, int i , int j);
void	destructor(t_sqr **sqr);

#endif
