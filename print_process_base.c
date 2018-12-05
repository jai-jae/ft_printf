/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_process_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:23:02 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/05 21:57:15 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_base(t_pfinfo *input)
{
	process_precision_nbr(input);
	if (input->flags.minus == 1)
	{
		print_sign_nbr(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_zerowidth_nbr(input);
	}
	else if (input->flags.zero == 1)
	{
		print_sign_nbr(input);
		print_zerowidth_nbr(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	else
	{
		print_zerowidth_nbr(input);
		print_sign_nbr(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
}
