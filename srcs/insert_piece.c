/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_i_j.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:42:15 by khrechen          #+#    #+#             */
/*   Updated: 2018/03/04 18:42:17 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft.h"

void				set_i_j(t_stuff *instance, int i, int j)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	while (y < instance->plateau->rows)
	{
		x = 0;
		while (x < instance->plateau->columns)
		{
			if (instance->plateau->sqr[y][x] == instance->enemy)
			{
				len = ft_abs(y - i) + ft_abs(x - j);
				if (len < instance->len)
				{
					instance->i = i;
					instance->j = j;
					instance->len = len;
				}
			}
			x++;
		}
		y++;
	}
}
