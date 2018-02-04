/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 14:40:30 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/04 16:21:42 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "libft.h"

static int	read_in_str(int const fd, char **str, char *buf)
{
	int			ret;
	char		*tmp;

	if ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(*str, buf)))
			return (-1);
		free(*str);
		*str = tmp;
	}
	return (ret);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	char		*n_index;
	int			ret;

	if (!str && !(str = (char *)ft_memalloc(sizeof(str))))
		return (ERROR);
	n_index = ft_strchr(str, '\n');
	while (!n_index)
		if (!(ret = read_in_str(fd, &str, buf)))
		{
			if ((n_index = ft_strchr(str, '\0')) == str)
				return (FINISH);
		}
		else if (ret < 0)
			return (ERROR);
		else
			n_index = ft_strchr(str, '\n');
	if (!(*line = ft_strsub(str, 0, n_index - str)))
		return (ERROR);
	n_index = ft_strdup(n_index + 1);
	free(str);
	str = n_index;
	return (READ);
}
