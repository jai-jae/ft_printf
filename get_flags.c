/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:50:53 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/07 00:29:50 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_pfinfo *e)
{
	e->flags.hash = 0;
	e->flags.zero = 0;
	e->flags.minus = 0;
	e->flags.plus = 0;
	e->flags.space = 0;
	e->flags.width = 0;
	e->flags.prec = -1;
	e->flags.neg = 0;
	e->mod = mod_non;
}

void	get_precision(const char *fmt, t_pfinfo *e)
{
	if (e->flags.prec >= 0)
	{
		e->i++;
		return ;
	}
	else if (fmt[e->i] == '.' && fmt[e->i + 1] == '*')
	{
		e->flags.prec = va_arg(e->ap, int);
		e->i += 2;
	}
	else if (fmt[e->i] == '.' && fmt[e->i + 1] >= '0'
			&& fmt[e->i + 1] <= '9')
	{
		e->i++;
		e->flags.prec = ft_atoi(fmt + e->i);
		while (ft_strchr(NBR, fmt[e->i]))
			e->i++;
	}
	else
		e->flags.prec = 0;
}

void	get_width(t_pfinfo *e)
{
	e->flags.width = va_arg(e->ap, int);
	if (e->flags.width < 0)
	{
		e->flags.width = -(e->flags.width);
		e->flags.minus = 1;
	}
}

void	get_mod(const char *fmt, t_pfinfo *e)
{
	if (fmt[e->i] == 'l' && fmt[e->i + 1] != 'l' &&
		e->mod == mod_non)
		e->mod = mod_l;
	else if (fmt[e->i] == 'l' && fmt[e->i + 1] == 'l')
		e->mod = mod_ll;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] != 'h' &&
			e->mod == mod_non)
		e->mod = mod_h;
	else if (fmt[e->i] == 'h' && fmt[e->i + 1] == 'h')
		e->mod = mod_hh;
	else if (fmt[e->i] == 'j')
		e->mod = mod_j;
	else if (fmt[e->i] == 'z')
		e->mod = mod_z;
	else if (fmt[e->i] == 'L')
		e->mod = mod_L;
}

void	get_flags(const char *fmt, t_pfinfo *e)
{
	init_flags(e);
	while (ft_strchr(FLAGS, fmt[e->i]))
	{
		fmt[e->i] == '#' ? e->flags.hash = 1 : 0;
		fmt[e->i] == '0' ? e->flags.zero = 1 : 0;
		fmt[e->i] == '-' ? e->flags.minus = 1 : 0;
		fmt[e->i] == '+' ? e->flags.plus = 1 : 0;
		fmt[e->i] == ' ' ? e->flags.space = 1 : 0;
		fmt[e->i] == '*' ? get_width(e) : 0;
		fmt[e->i] >= 'L' && fmt[e->i] <= 'z' ? get_mod(fmt, e) : 0;
		if (fmt[e->i] == '.')
			get_precision(fmt, e);
		else if (fmt[e->i] >= '1' && fmt[e->i] <= '9')
		{
			e->flags.width = ft_atoi(fmt + e->i);
			while (fmt[e->i] >= '0' && fmt[e->i] <= '9')
				e->i++;
		}
		else
			e->i++;
	}
}
