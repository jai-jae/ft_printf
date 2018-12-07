/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_process_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:23:02 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/06 11:45:32 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign_nbr(t_pfinfo *input)
{
	if (input->flags.plus || input->flags.space)
		input->ret += write(1, input->flags.plus == 1 ? "+" : " ", 1);
	if (input->flags.neg == 1)
		input->ret += write(1, "-", 1);
}

void	check_sign_nbr(t_pfinfo *input)
{
	char	*tmp;

	if (input->output[0] == '-')
	{
		tmp = ft_strdup(input->output + 1);
		free(input->output);
		input->output = tmp;
		input->flags.plus = 0;
		input->flags.space = 0;
		input->flags.neg = 1;
	}
}

void	process_precision_nbr(t_pfinfo *input)
{
	char	*zeros;
	char	*tmp;
	int		i;
	int		len;

	check_sign_nbr(input);
	len = (int)ft_strlen(input->output);
	if (input->flags.prec == 0 && input->output[0] == '0')
		input->output[0] = '\0';
	else if (input->flags.prec > len)
	{
		i = input->flags.prec - len;
		zeros = ft_strnew(i);
		while (i > 0)
			zeros[--i] = '0';
		tmp = ft_strjoin(zeros, input->output);
		free(zeros);
		free(input->output);
		input->output = tmp;
	}
	if (input->flags.prec >= 0)
		input->flags.zero = 0;
}

void	print_zerowidth_nbr(t_pfinfo *input)
{
	int len;
	int i;

	if (input->flags.plus == 1 || input->flags.space == 1 ||
			input->flags.neg == 1)
		len = (int)ft_strlen(input->output) + 1;
	else
		len = (int)ft_strlen(input->output);
	i = input->flags.width - ((input->flags.prec > (int)ft_strlen(input->output) ?
				input->flags.prec : 0) + len);
	while (i > 0)
	{	
		if (input->flags.zero == 1)
			input->ret += write(1, "0", 1);
		else
			input->ret += write(1, " ", 1);
		i--;
	}
}

void	print_nbr(t_pfinfo *input)
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
