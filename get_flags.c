/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:50:53 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 12:43:29 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->prec = -1;
	flags->neg = 0;
}

void		get_precision(const char *fmt, t_pfinfo *input)
{
	if (input->flags.prec >= 0)
	{
		input->i++;
		return ;
	}
	else if (fmt[input->i] == '.' && fmt[input->i + 1] == '*')
	{
		input->flags.prec = va_arg(input->ap, int); //TODO need check
		input->i += 2;
	}
	else if (fmt[input->i] == '.' && fmt[input->i + 1] >= '0'
			&& fmt[input->i + 1] <= '9')
	{
		input->i++;
		input->flags.prec = ft_atoi(fmt + input->i);
		while (ft_strchr(NBR, fmt[input->i]))
			input->i++;
	}
	else
		input->flags.prec = 0;
}

void		get_width(t_pfinfo *input)
{
	input->flags.width = va_arg(input->ap, int);
	if (input->flags.width < 0)
	{
		input->flags.width = -(input->flags.width);
		input->flags.minus = 1;
	}
	input->i++;
}

void		get_mod(const char *fmt, t_pfinfo *input) //TODO need check!!!
{
	if (fmt[input->i] == 'l' && fmt[input->i + 1] != 'l' &&
		input->mod == mod_non)
		input->mod = mod_l;
	else if (fmt[input->i] == 'l' && fmt[input->i + 1] == 'l')
		input->mod = mod_ll;
	else if (fmt[input->i] == 'h' && fmt[input->i + 1] != 'h' &&
			input->mod == mod_non)
		input->mod = mod_h;
	else if (fmt[input->i] == 'h' && fmt[input->i + 1] == 'h')
		input->mod = mod_hh;
	else if (fmt[input->i] == 'L')
		input->mod = mod_L;
}

void		get_flags(const char *fmt, t_pfinfo *input)
{
	init_flags(&(input->flags));
	while (ft_strchr(FLAGS, fmt[input->i]))
	{
		fmt[input->i] == '#' ? input->flags.hash = 1 : 0;
		fmt[input->i] == '0' ? input->flags.zero = 1 : 0;
		fmt[input->i] == '-' ? input->flags.minus = 1 : 0;
		fmt[input->i] == '+' ? input->flags.plus = 1 : 0;
		fmt[input->i] == ' ' ? input->flags.space = 1 : 0;
		fmt[input->i] == '*' ? get_width(input) : 0;
		if (fmt[input->i] == 'L' || fmt[input->i] == 'l'
		|| fmt[input->i] == 'h')
			get_mod(fmt, input);
		if (fmt[input->i] == '.')
			get_precision(fmt, input);
		else if (fmt[input->i] >= '1' && fmt[input->i] <= '9')
		{
			input->flags.width = ft_atoi(fmt + input->i);
			while (fmt[input->i] >= '0' && fmt[input->i] <= '9')
				input->i++;
		}
		else
			input->i++;
	}
}
