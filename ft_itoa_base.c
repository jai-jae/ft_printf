/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:21:36 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/22 00:26:25 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, long int base)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp >= base)
	{
		tmp /= base;
		len++;
	}
	if (!(val = ft_strnew(len)))
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
