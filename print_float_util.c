/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:07:39 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 21:53:04 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"

void	print_sign_float(t_pfinfo *e)
{
	if (e->flags.plus == 1 || e->flags.space == 1)
		e->ret += write(e->fd, e->flags.plus == 1 ? "+" : " ", 1);
	if (e->flags.neg == 1)
		e->ret += write(e->fd, "-", 1);
}

void	check_sign_float(t_pfinfo *e)
{
	e->flags.neg = 1;
	e->flags.plus = 0;
	e->flags.space = 0;
}

void	carry_floats(t_fprec *nbr, t_pfinfo *e)
{
	int	carry;

	carry = e->flags.prec;
	while (e->bf[nbr->dot + carry] == '9')
	{
		e->bf[nbr->dot + carry] = '0';
		carry--;
	}
	e->bf[nbr->dot + carry] += 1;
}
