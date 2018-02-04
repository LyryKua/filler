/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 19:05:48 by khrechen          #+#    #+#             */
/*   Updated: 2018/02/03 19:33:46 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <zconf.h>
#include "ft_printf.h"
#include "libft.h"

void	error_exit(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(1);
}

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc != 2)
		error_exit("usage: input");
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	close(fd);
//	while (42);
	return (0);
}
