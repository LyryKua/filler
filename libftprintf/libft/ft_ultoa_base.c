/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khrechen <khrechen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:44:00 by khrechen          #+#    #+#             */
/*   Updated: 2018/01/08 17:44:00 by khrechen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	value_len(unsigned long value, int base)
{
	size_t	len;

	len = 1;
	while (value /= base)
		len++;
	return (len);
}

char			*ft_ultoa_base(unsigned long value, int base)
{
	char	*str;
	char	*alphabet;
	size_t	len;

	if (value == 0)
		return (ft_strdup("0"));
	alphabet = "0123456789abcdef";
	len = value_len(value, base);
	str = ft_strnew(len);
	while (len)
	{
		str[len-- - 1] = alphabet[value % base];
		value /= base;
	}
	return (str);
}
