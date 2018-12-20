/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:21:20 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 15:47:12 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void		print_width_addr(t_pfinfo *input)
{
	int len;
	int i;

	len = ft_strlen(input->output) + 2;
	i = input->flags.width - len;
	while (i > 0)
	{
		input->ret += write(1, " ", 1);
		i--;
	}
}

void			print_addr(t_pfinfo *input)
{
	input->flags.zero = 0;
	input->flags.space = 0;
	input->flags.plus = 0;
	input->flags.hash = 1;
	input->flags.prec = -1;
	if (input->flags.minus == 1)
	{
		print_hash_base('x', input);
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_width_addr(input);
	}
	else
	{
		print_width_addr(input);
		print_hash_base('x', input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
}

static void     print_width_chars(t_pfinfo *input)
{
	int len;
	int i;

	len = ft_strlen(input->output) + 2;
	i = input->flags.width - len;
	while (i > 0)
	{
		input->ret += write(1, " ", 1);
		i--;
	}
}

void            print_char(t_pfinfo *input)
{
	input->flags.zero = 0;
	input->flags.space = 0;
	input->flags.plus = 0;
	input->flags.hash = 0;
	input->flags.prec = -1;
	if (input->flags.minus == 1)
	{
		input->ret += write(1, input->output, ft_strlen(input->output));
		print_width_addr(input);
	}
	else
	{
		print_width_addr(input);
		input->ret += write(1, input->output, ft_strlen(input->output));
	}
	input->i++;
}
