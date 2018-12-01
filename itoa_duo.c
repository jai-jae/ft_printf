/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_duo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:49:17 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 22:56:44 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*itoa(int n, long int base)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) + '0';
		tmp /= base;
	}
	val[--len] = (tmp % base) + '0';
	return (val);
}

char	*itoa_base(int n, long int base)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -(long int)n : n;
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
