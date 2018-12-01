/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:03:56 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 23:06:30 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char		*ltoa(long int n, long int base)
{
	char			*val;
	int				len;
	long int		tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -n : n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -n : n;
	while (tmp >= base)
	{
		val[--len] = (tmp % base) + '0';
		tmp /= ft_strlen(base);
	}
	val[--len] = (tmp % base) + '0';
	return (val);
}
char		*ltoa_base(long int n, long int base)
{
	char			*val;
	int				len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -n : n;
	while (tmp > base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -n : n;
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
