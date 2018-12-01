/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:53:15 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/11 12:18:36 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	unsigned int	tmp;

	tmp = 0;
	if (n >= 0)
		tmp = n;
	else if (n < 0)
	{
		ft_putchar('-');
		tmp = (unsigned int)(n * (-1));
	}
	if (tmp > 9)
	{
		ft_putnbr(tmp / 10);
		ft_putchar((tmp % 10) + '0');
	}
	else
		ft_putchar(tmp + '0');
}
