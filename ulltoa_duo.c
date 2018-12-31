/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_duo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:02:33 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/27 16:13:42 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ulltoa(unsigned long long int n)
{
	char					*val;
	int						len;
	unsigned long long int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	if (!(val = ft_memalloc(len + 1)))
		return (NULL);
	val[len] = '\0';
	tmp = n;
	while (tmp >= 10)
	{
		val[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	val[--len] = (tmp % 10) + '0';
	return (val);
}

char	*ulltoa_base(unsigned long long int n, unsigned long long int base)
{
	char					*val;
	int						len;
	unsigned long long int	tmp;

	len = 1;
	tmp = n;
	while (tmp >= base)
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
