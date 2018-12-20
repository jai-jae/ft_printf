/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:24:31 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 15:47:07 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	get_addr(t_pfinfo *input)
{
	unsigned long int val;

	val = va_arg(input->ap, unsigned long int);
	input->output = ultoa_base(val, 16);
	if (!input->output)
		return ;
	ft_strlower(input->output);
	print_addr(input);
}

void	get_chars(char type, t_pfinfo *input)
{
	char	*string;
 	char	ch;

	string = NULL;
	if (type == 's')
	{
		input->output = input->mod == mod_l ? 
		va_arg(input->ap, wchar_t*) : va_arg(input->ap, const char*);
		print_string(input);
	}
	else
	{
		ch = input->mod == mod_l ?
		(char)va_arg(input->ap, int) : (char)va_arg(input->ap, wint_t);
		input->output = &c;
		print_char(input);
	}
}
