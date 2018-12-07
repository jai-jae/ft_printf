/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr_process_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:23:02 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/06 14:08:56 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_hash_base(char type, t_pfinfo *input)
{
	char    *tmp;
	char	*hash;
	if (type == 'o')
		input->ret += write(1, "0", 1);
	else if (type == 'x' || type == 'X')
		input->ret += write(1, type == 'x' ? "0x" : "0X", 2);
}

void    process_precision_base(char type, t_pfinfo *input)
{
	char    *zeros;
	char    *tmp;
	int     i;
	int     len;

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

void	print_zerowidth_base(char type, t_pfinfo *input)
{
	int	len;
	int	i;

	if (input->flags.hash == 1 && type == 'o')
		len = (int)ft_strlen(input->output) + 1;
	else if (input->flags.hash == 1 && (type == 'X' || type == 'x'))
		len = (int)ft_strlen(input->output) + 2;
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

void	print_base(char type, t_pfinfo *input)
{
	process_precision_base(type, input);
	if (input->flags.minus == 1)
	{
		input->flags.hash == 1 ? print_hash_base(type, input) : 0;
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_zerowidth_base(type, input);
	}
	else if (input->flags.zero == 1)
	{
		input->flags.hash == 1 ? print_hash_base(type, input) : 0;
		print_zerowidth_base(type, input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	else
	{
		print_zerowidth_base(type, input);
		input->flags.hash == 1 ? print_hash_base(type, input) : 0;
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
}
