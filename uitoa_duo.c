/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_duo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:52:27 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 22:56:41 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*uitoa(unsigned int n, unsigned int base)
{
	char			*val;
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) + '0';
	return (val);
}

char	*uitoa_base(unsigned int n, unsigned int base)
{
	char			*val;
	int				len;
	unsigned int	tmp;

	len = 1;
	tmp = n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) > 9 ?
			(tmp % base) + 55 : (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) > 9 ?
		(tmp % base) + 55 : (tmp % base) + '0';
	return (val);
}
