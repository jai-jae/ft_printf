/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 04:20:03 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:13:14 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"

static void		err_message(t_fprec *nbr, t_pfinfo *input)
{
	if (nbr->err == nan)
		input->output = ft_strdup("nan");
	else if (nbr->err == NAN)
		input->output = ft_strdup("NAN");
	else if (nbr->err == inf)
		input->output = ft_strdup("inf");
	else if (nbr->err == INF)
		input->output = ft_strdup("INF");
	else if (nbr->err == zero)
		input->output = ft_strdup("0.0");
}

static void		print_width_float_error(t_pfinfo *input)
{
	int	len;
	int	i;

	if (input->flags.plus == 1 || input->flags.space == 1 ||
			input->flags.neg == 1)
		len = 4;
	else
		len = 3;
	i = input->flags.width - len;
	while (i > 0)
	{
		input->ret += write(1, " ", 1);
		i--;
	}
}

void			print_float_error(t_fprec *nbr, t_pfinfo *input)
{
	err_message(nbr, input);
	if (!(input->output))
		return ;
	if (nbr->err == zero)
		print_float(nbr, input);
	else
	{
		nbr->sign == 1 ? check_sign_float(input) : 0;
		input->flags.zero = 0;
		if (input->flags.minus == 1)
		{
			print_sign_float(input);
			input->ret += write(1, input->output, ft_strlen(input->output));
			print_width_float_error(input);
		}
		else
		{
			print_width_float_error(input);
			print_sign_float(input);
			input->ret += write(1, input->output, ft_strlen(input->output));
		}
		input->i++;
		free(input->output);
	}
}
