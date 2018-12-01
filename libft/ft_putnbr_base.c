/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:51:12 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/13 16:53:39 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_exceptions(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	int				j;
	unsigned int	tmp;

	i = 0;
	j = 0;
	if (ft_exceptions(base) == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		tmp = nbr * (-1);
	}
	else
		tmp = nbr;
	while (base[i] != '\0')
		i++;
	if (tmp >= i)
		ft_putnbr_base(tmp / i, base);
	ft_putchar(base[tmp % i]);
	return ;
}
