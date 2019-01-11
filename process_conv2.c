/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:24:31 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 22:04:36 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	get_addr(t_pfinfo *e)
{
	unsigned long int val;

	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	val = va_arg(e->ap, unsigned long int);
	if (e->flags.prec == 0)
		e->bf = ft_strdup("\0");
	else
		e->bf = ultoa_base(val, 16);
	if (!e->bf)
		return ;
	ft_strlower(e->bf);
	print_addr(e);
}

void	get_chars(char type, t_pfinfo *e)
{
	unsigned char	ch;
	char			*str;

	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	if (type == 's')
	{
		str = (char*)va_arg(e->ap, char*);
		if (str == NULL)
			return (print_null_str(e));
		if (!(e->bf = ft_strdup(str)))
			return ;
		print_str(e);
	}
	else if (type == 'c')
	{
		ch = (unsigned char)va_arg(e->ap, int);
		print_char(e, ch);
	}
}

void	get_percent(t_pfinfo *e)
{
	if (e->flags.minus == 1)
	{
		e->ret += write(e->fd, "%", 1);
		while (e->flags.width-- > 1)
			e->ret += write(e->fd, " ", 1);
	}
	else
	{
		while (e->flags.width-- > 1)
			e->ret += (e->flags.zero ?
					write(e->fd, "0", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, "%", 1);
	}
	e->i++;
}
