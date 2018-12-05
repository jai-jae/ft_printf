/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:58 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/05 23:06:53 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static void		get_input(const char *fmt, t_pfinfo *input)
{
	input->i++;
	get_flags(fmt, input);
	get_datatype(fmt, input);
	//TODO don't know what to do T-T
}

int				ft_printf(const char *fmt, ...)
{
	t_pfinfo	input;
	
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

int main()
{
	int a;
	a = -65535;
	ft_printf("%10.0d\n", a);
	   printf("%10.0d\n", a);
	return (0);
}	
