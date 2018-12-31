/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:58 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/27 16:33:17 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		get_input(const char *fmt, t_pfinfo *input)
{
	input->i++;
	get_flags(fmt, input);
	if (input->i > (int)ft_strlen(fmt) - 1)
		return ;
	get_datatype(fmt, input);
}

int				ft_printf(const char *fmt, ...)
{
	t_pfinfo		input;
	int				len;

	ft_bzero(&input, sizeof(input));
	va_start(input.ap, fmt);
	if (fmt)
	{
		len = (int)ft_strlen(fmt);
		while (input.i < len)
		{
			if (fmt[input.i] == '%' && len == 1)
				break ;
			if (fmt[input.i] == '%' && fmt[input.i + 1] != '%')
				get_input(fmt, &input);
			else if (fmt[input.i] == '%' && fmt[input.i + 1] == '%')
			{
				input.ret += write(1, "%", 1);
				input.i += 2;
			}
			else
				input.ret += write(1, &fmt[input.i++], 1);
		}
	}
	va_end(input.ap);
	return (input.ret);
}
