/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:03:03 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:12:13 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"

void	print_integer(t_fprec *nbr, t_pfinfo *input)
{
	int index;

	if (input->flags.prec == 0)
	{
		input->output[nbr->dot + 1] > '4' ?
		input->output[nbr->dot - 1] += 1 : 0;
	}
	index = 0;
	while (input->output[index] != '.')
		index++;
	input->ret += write(1, input->output, index);
}

void	print_precision(t_fprec *nbr, t_pfinfo *input)
{
	int		len;
	int		i;
	char	*zeros;

	len = (int)ft_strlen(input->output + nbr->dot + 1);
	if (input->flags.prec == len || input->flags.prec == len - 1)
		write(1, input->output + nbr->dot,
				input->flags.prec == len ? len + 1 : len);
	else if (input->flags.prec < len)
	{
		input->output[nbr->dot + input->flags.prec + 1] > '4' ?
			carry_floats(nbr, input) : 0;
		input->ret += write(1, input->output + nbr->dot, input->flags.prec + 1);
	}
	else
	{
		i = input->flags.prec - len;
		input->ret += write(1, input->output + nbr->dot, len + 1);
		zeros = ft_strnew(i);
		while (i > 0)
			zeros[--i] = '0';
		write(1, zeros, input->flags.prec - len);
	}
}

void	print_zerowidth_float(t_pfinfo *input)
{
	int len_inte;
	int	i;

	len_inte = 0;
	while (input->output[len_inte] != '.')
		len_inte++;
	if (input->flags.plus == 1 || input->flags.space == 1 ||
			input->flags.neg == 1)
		len_inte += 1;
	input->flags.prec != 0 ? len_inte += 1 : 0;
	i = input->flags.width - (len_inte + input->flags.prec);
	while (i > 0)
	{
		if (input->flags.zero == 1)
			input->ret += write(1, "0", 1);
		else
			input->ret += write(1, " ", 1);
		i--;
	}
}

void	print_float(t_fprec *nbr, t_pfinfo *input)
{
	nbr->sign == 1 ? check_sign_float(input) : 0;
	input->flags.prec < 0 ? input->flags.prec = 6 : 0;
	if (input->flags.minus == 1)
	{
		print_sign_float(input);
		print_integer(nbr, input);
		input->flags.prec > 0 ? print_precision(nbr, input) : 0;
		print_zerowidth_float(input);
	}
	else if (input->flags.zero == 1)
	{
		print_sign_float(input);
		print_zerowidth_float(input);
		print_integer(nbr, input);
		input->flags.prec > 0 ? print_precision(nbr, input) : 0;
	}
	else
	{
		print_zerowidth_float(input);
		print_sign_float(input);
		print_integer(nbr, input);
		input->flags.prec > 0 ? print_precision(nbr, input) : 0;
	}
	input->i++;
	free(input->output);
}
