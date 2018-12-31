/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:19:21 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/22 08:04:28 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*val;
	int			len;
	long int	tmp;

	len = n < 0 ? 2 : 1;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	if (!(val = ft_strnew(len)))
		return (NULL);
	val[len] = '\0';
	val[0] = n < 0 ? '-' : 0;
	tmp = n < 0 ? -(long int)n : n;
	while (tmp >= 10)
	{
		val[--len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	val[--len] = (tmp % 10) + '0';
	return (val);
}
