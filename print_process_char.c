/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:03:05 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:55:44 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_zerowidth_char(t_pfinfo *e)
{
	int i;

	i = e->flags.width - 1;
	while (i > 0)
	{
		e->ret += ((e->flags.zero == 1) ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		i--;
	}
}

void	print_char(t_pfinfo *e, unsigned char ch)
{
	if (e->flags.minus)
	{
		e->ret += write(e->fd, &ch, 1);
		print_zerowidth_char(e);
	}
	else
	{
		print_zerowidth_char(e);
		e->ret += write(e->fd, &ch, 1);
	}
	e->i++;
}
