/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_process_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:03:05 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:27:42 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_zerowidth_char(t_pfinfo *input)
{
	int i;
	i = input->flags.width - 1;
	while (i > 0)
	{
		input->ret += ((input->flags.zero == 1) ?
			write(1, "0", 1) : write(1, " ", 1));
		i--;
	}
}

void	print_char(t_pfinfo *input, char ch)
{
	if (input->flags.minus)
	{
		input->ret += write(1, &ch, 1);
		print_zerowidth_char(input);
	}
	else
	{
		print_zerowidth_char(input);
		input->ret += write(1, &ch, 1);
	}
	input->i++;
}

