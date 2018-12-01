/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_duo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:02:33 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 23:04:14 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*lltoa(long long int n, long long int base)
{
	char					*val;
	int						len;
	unsigned long long int	tmp;

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
		tmp /= ft_strlen(base);
	}
	val[--len] = (tmp % base) + '0';
	return (val);
}

char	*lltoa_base(long long int n, long long int base)
{
	char					*val;
	int						len;
	unsigned long long int	tmp;

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
