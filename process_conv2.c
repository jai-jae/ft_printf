/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:24:31 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 18:30:07 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	get_addr(t_pfinfo *input)
{
	unsigned long int val;

	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	val = va_arg(input->ap, unsigned long int);
	input->output = ultoa_base(val, 16);
	if (!input->output)
		return ;
	ft_strlower(input->output);
	print_addr(input);
}

void	get_chars(char type, t_pfinfo *input)
{
	char	ch;
	char	*str;
	
	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	if (type == 's')
	{
		str = (char*)va_arg(input->ap, char*);
		if (str == NULL)
			return (print_null_str(input));
		if (!(input->output = ft_strdup(str)))
			return ;
		print_str(input);
	}
	else if (type == 'c')
	{
		ch = (char)va_arg(input->ap, int);
		print_char(input, ch);
	}
}
