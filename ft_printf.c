/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:58 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 22:11:32 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		get_input(const char *fmt, t_pfinfo *e)
{
	e->i++;
	get_flags(fmt, e);
	if (e->i > (int)ft_strlen(fmt) - 1)
		return ;
	get_datatype(fmt, e);
}

int				ft_printf(const char *fmt, ...)
{
	t_pfinfo		e;
	int				len;

	ft_bzero(&e, sizeof(e));
	va_start(e.ap, fmt);
	if ((e.fd = 1) && fmt)
	{
		len = (int)ft_strlen(fmt);
		while (e.i < len)
		{
			if (fmt[e.i] == '%' && len == 1)
				break ;
			if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
				get_input(fmt, &e);
			else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
			{
				e.ret += write(e.fd, "%", 1);
				e.i += 2;
			}
			else
				e.ret += write(e.fd, &fmt[e.i++], 1);
		}
	}
	va_end(e.ap);
	return (e.ret);
}

int				ft_dprintf(int fd, const char *fmt, ...)
{
	t_pfinfo		e;
	int				len;

	ft_bzero(&e, sizeof(e));
	va_start(e.ap, fmt);
	if ((e.fd = fd) && fmt)
	{
		len = (int)ft_strlen(fmt);
		while (e.i < len)
		{
			if (fmt[e.i] == '%' && len == 1)
				break ;
			if (fmt[e.i] == '%' && fmt[e.i + 1] != '%')
				get_input(fmt, &e);
			else if (fmt[e.i] == '%' && fmt[e.i + 1] == '%')
			{
				e.ret += write(e.fd, "%", 1);
				e.i += 2;
			}
			else
				e.ret += write(e.fd, &fmt[e.i++], 1);
		}
	}
	va_end(e.ap);
	return (e.ret);
}
