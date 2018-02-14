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

typedef struct s_plateau	t_plateau;
struct		s_plateau
{
	int		rows;
	int		columns;
	char	**sqr;
	char	**(*read)(t_plateau *, int);
	void	(*destructor)(t_plateau *);
};
t_plateau	plateau_init(int fd);
char		**plateau_read(t_plateau *plateau, int fd);
void		plateau_desturctor(t_plateau *plateau);

/*
** *********************************** Piece ***********************************
*/

typedef struct s_piece		t_piece;
struct		s_piece
{
	int		rows;
	int		columns;
	char	**sqr;
	char	**(*read)(t_piece *, int);
	void	(*destructor)(t_piece *);
};
t_piece		piece_init(int fd);
char		**piece_read(t_piece *piece, int fd);
void		piece_desturctor(t_piece *piece);

/*
** *********************************** Piece ***********************************
*/

typedef struct s_stuff		t_stuff;

struct		s_stuff
{
	char		me;
	t_plateau	plateau;
	t_piece		*piece;
	char		**(*insert_piece)(t_stuff *);
};
char		**insert_piece(t_stuff *instance);

t_piece		*read_piece(int fd);

#endif
