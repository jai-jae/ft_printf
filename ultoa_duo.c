/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa_duo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:58:11 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 23:01:38 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

char	*ultoa(unsigned long int n, unsigned long int base)
{
	char				*val;
	int					len;
	unsigned long int	tmp;

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
char	*ultoa_base(unsigned long int n, unsigned long int base)
{
	char				*val;
	int					len;
	unsigned long int	tmp;

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
