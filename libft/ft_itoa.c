/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:54:22 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/29 11:59:24 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_digit(int n)
{
	int	cnt;
	int	tmp;

	tmp = n;
	cnt = 0;
	while (tmp)
	{
		tmp /= 10;
		cnt++;
	}
	if (cnt == 0)
		return (1);
	else if (n < 0)
		return (cnt + 1);
	return (cnt);
}

static char		*ft_nbr_to_char(int n, char *val, int len)
{
	int	tmp;

	tmp = n;
	val[len] = '\0';
	while (len >= 0)
	{
		len--;
		if (n < 0)
		{
			val[len] = ((tmp % 10) * (-1) + '0');
			tmp /= 10;
		}
		else
		{
			val[len] = ((tmp % 10) + '0');
			tmp /= 10;
		}
		if (n < 0)
			val[0] = '-';
	}
	return (val);
}

char			*ft_itoa(int n)
{
	char	*val;
	int		len;

	len = ft_digit(n);
	val = ft_memalloc(len + 1);
	if (!(val))
		return (NULL);
	val = ft_nbr_to_char(n, val, len);
	return (val);
}
