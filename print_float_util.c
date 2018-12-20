/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:07:39 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 11:02:15 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"

void	print_sign_float(t_pfinfo *input)
{
	if (input->flags.plus == 1 || input->flags.space == 1)
		input->ret += write(1, input->flags.plus == 1 ? "+" : " ", 1);
	if (input->flags.neg == 1)
		input->ret += write(1, "-", 1);
}

void	check_sign_float(t_pfinfo *input)
{
	input->flags.neg = 1;
	input->flags.plus = 0;
	input->flags.space = 0;
}

void	carry_floats(t_fprec *nbr, t_pfinfo *input)
{
	int	carry;

	carry = input->flags.prec;
	while (input->output[nbr->dot + carry] == '9')
	{
		input->output[nbr->dot + carry] = '0';
		carry--;
	}
	input->output[nbr->dot + carry] += 1;
}
