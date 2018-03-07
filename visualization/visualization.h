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

# define WIDTH	1440
# define HEIGHT	900
# define X	20

typedef struct s_graphics	t_graphics;
typedef struct s_rect		t_rect;
typedef struct s_point		t_point;

struct	s_point
{
	int				x;
	int				y;
	unsigned int	color;
};

struct	s_rect
{
	int	x;
	int	y;
	int	w;
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
	void	(*put_pixel)(t_graphics *, int, int, unsigned int);
};

t_graphics	*init_graphics(int width, int height, char *title);

/* ************************************************************************** */


typedef struct s_sqr	t_sqr;
typedef struct s_stuff	t_stuff;
typedef struct s_all	t_all;

struct	s_all
{
	t_stuff		*instance;
	t_graphics	*graphics;
	int			fd;
	int			x;
};

struct	s_sqr
{
	int		rows;
	int		columns;
	char	**sqr;
};

struct	s_stuff
{
	t_sqr	*plateau;
	t_sqr	*(*read)(char *, int);
	void	(*destructor)(t_sqr **);
};

t_stuff	*init_stuff();

void	draw(t_graphics *graphics, t_stuff *instance, int x);
void	fill_rectangle(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_old_x(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_new_x(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_old_o(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_new_o(t_graphics *graphics, t_rect *rect, unsigned int color);
void	draw_grid(t_graphics *graphics, int x);

#endif
