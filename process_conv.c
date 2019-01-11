/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:50:17 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/03 22:01:28 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"
#include "bigint.h"

void	get_base(char type, t_pfinfo *e)
{
	unsigned long int	val;

	init_uint_arg(type, e, &val);
	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	e->flags.plus = 0;
	e->flags.space = 0;
	if (type == 'b')
		get_binary(e, val);
	else if (type == 'o')
		get_octal(e, val);
	else if (type == 'X' || type == 'x')
		get_hexa(e, val);
	if (!(e->bf))
		return ;
	if (type == 'x')
		ft_strlower(e->bf);
	print_base(type, e);
}

void	get_int(t_pfinfo *e)
{
	long int	val;

	init_int_arg(e, &val);
	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	if (val == LLONG_MIN || val == LONG_MIN)
		e->bf = ft_strdup("-9223372036854775808");
	else if (e->mod == mod_non)
		e->bf = ft_itoa((int)val);
	else if (e->mod == mod_hh)
		e->bf = ft_itoa((char)val);
	else if (e->mod == mod_h)
		e->bf = ft_itoa((short int)val);
	else if (e->mod == mod_l || e->mod == mod_j || e->mod == mod_z)
		e->bf = ltoa((long int)val);
	else if (e->mod == mod_ll)
		e->bf = lltoa((long long int)val);
	if (e->bf)
		print_nbr(e);
}

void	get_uint(char type, t_pfinfo *e)
{
	unsigned long int val;

	init_uint_arg(type, e, &val);
	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	e->flags.space = 0;
	e->flags.plus = 0;
	if (type == 'U')
		e->bf = ultoa((unsigned long int)val);
	else
	{
		if (e->mod == mod_non)
			e->bf = ft_uitoa((unsigned int)val);
		else if (e->mod == mod_hh)
			e->bf = ft_uitoa((unsigned char)val);
		else if (e->mod == mod_h)
			e->bf = ft_uitoa((unsigned short int)val);
		else if (e->mod == mod_l || e->mod == mod_j ||
				e->mod == mod_z)
			e->bf = ultoa((unsigned long int)val);
		else if (e->mod == mod_ll)
			e->bf = ulltoa((unsigned long long int)val);
	}
	if (e->bf)
		print_nbr(e);
}

void	get_float(char type, t_pfinfo *e)
{
	double			d;
	long double		ld;
	t_fprec			nbr;
	int				error;

	init_fprec(&nbr);
	e->flags.minus == 1 ? e->flags.zero = 0 : 0;
	if (e->mod == mod_L)
	{
		ld = va_arg(e->ap, long double);
		error = float_80(ld, &nbr);
	}
	else
	{
		d = va_arg(e->ap, double);
		error = float_64(d, &nbr);
	}
	if (!error)
	{
		e->bf = ft_ftoa(&nbr);
		if (e->bf)
			print_float(&nbr, e);
	}
	else
		print_float_error(type, &nbr, e);
}

void	get_datatype(const char *fmt, t_pfinfo *e)
{
	if (ft_strchr(BASE, fmt[e->i]))
		get_base(fmt[e->i], e);
	else if (fmt[e->i] == '%')
		get_percent(e);
	else if (fmt[e->i] == 'd' || fmt[e->i] == 'i')
		get_int(e);
	else if (fmt[e->i] == 'u' || fmt[e->i] == 'U')
		get_uint(fmt[e->i], e);
	else if (fmt[e->i] == 'c' || fmt[e->i] == 's')
		get_chars(fmt[e->i], e);
	else if (fmt[e->i] == 'p')
		get_addr(e);
	else if (fmt[e->i] == 'f' || fmt[e->i] == 'F')
		get_float(fmt[e->i], e);
	else if (fmt[e->i] != '\0')
		print_char(e, fmt[e->i]);
}
