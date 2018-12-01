/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:58 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 12:49:22 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"

static	void	init_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->prec = -1;
}

static void		get_input(const char *fmt, t_pfinfo *input)
{
	input->i++;
	get_flags(fmt, input);
	//process_conv();
	//TODO don't know what to do T-T
}

int				ft_printf(const char *fmt, ...)
{
	t_pfinfo	input;
	
	ft_bzero(&input, sizeof(input));
	va_start(input.ap[0], fmt);
	va_copy(intput.ap[1], input.ap[0]);
	while (fmt[input->i])
	{
		if (fmt[input->i] == '%' && fmt[input->i + 1] != '%')
			process_input(fmt, &input);
		else if (fmt[input->i] == '%' && fmt[input->i + 1] == '%')
		{
			input.ret += write(1, "%", 1);
			input->i += 2;
		}
		else
		{
			input.ret += write(1, &fmt[input.i], 1);
			input.i++;
		}
	}
	va_end(input.ap[0]);
	return (input.ret);
}
