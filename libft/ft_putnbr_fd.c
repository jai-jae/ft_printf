/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:46:13 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/11 12:21:47 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = 0;
	if (n >= 0)
		tmp = n;
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = (unsigned int)(n * (-1));
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putchar_fd((tmp % 10) + '0', fd);
	}
	else
		ft_putchar_fd(tmp + '0', fd);
}
