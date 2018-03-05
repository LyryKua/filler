/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:47:24 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/05 12:47:28 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZATION_H
# define VISUALIZATION_H

typedef struct s_graphics	t_graphics;
typedef struct s_point		t_point;

struct		s_point
{
	int				x;
	int				y;
	unsigned int	color;
};

struct	s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		sl;
	int		e;
	int		w;
	int		h;
	void	(*put_pixel)(t_graphics *, t_point *);
	void	(*destructor)(t_graphics **);
};

t_graphics	*init_graphics(int width, int height, char *title);

/* ************************************************************************** */


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
	t_sqr	*plateau;
	t_sqr	*(*read_plateau)(char *);
	t_sqr	*piece;
	t_sqr	*(*read_piece)(void);
	void	(*destructor)(t_sqr **);
};

t_stuff	*init_stuff();

#endif
