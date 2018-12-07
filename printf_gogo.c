/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_gogo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:28:32 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/06 20:29:12 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void     get_input(const char *fmt, t_pfinfo *input)
{
	input->i++;
	get_flags(fmt, input);
	get_datatype(fmt, input);
}

int             ft_printf(const char *fmt, ...)
{
	t_pfinfo    input;

	ft_bzero(&input, sizeof(input));
	va_start(input.ap, fmt);
	while (fmt[input.i])
	{
		if (fmt[input.i] == '%' && fmt[input.i + 1] != '%')
			get_input(fmt, &input);
		else if (fmt[input.i] == '%' && fmt[input.i + 1] == '%')
		{
			input.ret += write(1, "%", 1);
			input.i += 2;
		}
		else
		{
			input.ret += write(1, &fmt[input.i], 1);
			input.i++;
		}
	}
	va_end(input.ap);
	return (input.ret);
}
