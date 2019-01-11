/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:03:56 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/22 08:07:14 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char		*ltoa(long int n)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -n : n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	if (!(val = ft_strnew(len)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -n : n;
	while (tmp >= 10)
	{
		val[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	val[--len] = (tmp % 10) + '0';
	return (val);
}

char		*ltoa_base(long int n, long int base)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -n : n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_strnew(len)))
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
