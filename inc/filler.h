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

# define X	'X'
# define O	'O'
# define FD	fd

/*
** ********************************** Plateau **********************************
*/

typedef struct s_sqr	t_sqr;
struct		s_sqr
{
	int		rows;
	int		columns;
	char	**sqr;
	char	**(*read)(t_sqr *, int);
	void	(*destructor)(t_sqr *);
};
t_sqr		piece_init(int fd);
t_sqr		plateau_init(int fd);
char		**piece_read(t_sqr *piece, int fd);
char		**plateau_read(t_sqr *plateau, int fd);
void		desturctor(t_sqr *sqr);

/*
** *********************************** Piece ***********************************
*/

typedef struct s_stuff		t_stuff;

struct		s_stuff
{
	char		me;
	t_sqr		plateau;
	t_sqr		piece;
	char		**(*insert_piece)(t_stuff *);
};
char		**insert_piece(t_stuff *instance);

#endif
