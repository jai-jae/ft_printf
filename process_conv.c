/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:50:17 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/28 15:50:00 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fpoint.h"
#include "bigint.h"

void	get_base(char type, t_pfinfo *input)
{
	unsigned long int	val;

	init_uint_arg(type, input, &val);
	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	input->flags.plus = 0;
	input->flags.space = 0;
	if (type == 'b')
		get_binary(input, val);
	else if (type == 'o')
		get_octal(input, val);
	else if (type == 'X' || type == 'x')
		get_hexa(input, val);
	if (!(input->output))
		return ;
	if (type == 'x')
		ft_strlower(input->output);
	print_base(type, input);
}

void	get_int(t_pfinfo *input)
{
	long int	val;

	init_int_arg(input, &val);
	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	if (val == LLONG_MIN || val == LONG_MIN)
		input->output = ft_strdup("-9223372036854775808");
	else if (input->mod == mod_non)
		input->output = ft_itoa((int)val);
	else if (input->mod == mod_hh)
		input->output = ft_itoa((char)val);
	else if (input->mod == mod_h)
		input->output = ft_itoa((short int)val);
	else if (input->mod == mod_l || input->mod == mod_j || input->mod == mod_z)
		input->output = ltoa((long int)val);
	else if (input->mod == mod_ll)
		input->output = lltoa((long long int)val);
	if (input->output)
		print_nbr(input);
}

void	get_uint(char type, t_pfinfo *input)
{
	unsigned long int val;

	init_uint_arg(type, input, &val);
	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	input->flags.space = 0;
	input->flags.plus = 0;
	if (type == 'U')
		input->output = ultoa((unsigned long int)val);
	else
	{
		if (input->mod == mod_non)
			input->output = ft_uitoa((unsigned int)val);
		else if (input->mod == mod_hh)
			input->output = ft_uitoa((unsigned char)val);
		else if (input->mod == mod_h)
			input->output = ft_uitoa((unsigned short int)val);
		else if (input->mod == mod_l || input->mod == mod_j ||
				input->mod == mod_z)
			input->output = ultoa((unsigned long int)val);
		else if (input->mod == mod_ll)
			input->output = ulltoa((unsigned long long int)val);
	}
	if (input->output)
		print_nbr(input);
}

void	get_float(char type, t_pfinfo *input)
{
	double			d;
	long double		ld;
	t_fprec			nbr;
	int				error;

	init_fprec(&nbr);
	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	if (input->mod == mod_L)
	{
		ld = va_arg(input->ap, long double);
		error = float_80(ld, &nbr);
	}
	else
	{
		d = va_arg(input->ap, double);
		error = float_64(d, &nbr);
	}
	if (!error)
	{
		input->output = ft_ftoa(&nbr);
		if (input->output)
			print_float(&nbr, input);
	}
	else
		print_float_error(type, &nbr, input);
}

void	get_datatype(const char *fmt, t_pfinfo *input)
{
	if (ft_strchr(BASE, fmt[input->i]))
		get_base(fmt[input->i], input);
	else if (fmt[input->i] == '%')
		get_percent(input);
	else if (fmt[input->i] == 'd' || fmt[input->i] == 'i')
		get_int(input);
	else if (fmt[input->i] == 'u' || fmt[input->i] == 'U')
		get_uint(fmt[input->i], input);
	else if (fmt[input->i] == 'c' || fmt[input->i] == 's')
		get_chars(fmt[input->i], input);
	else if (fmt[input->i] == 'p')
		get_addr(input);
	else if (fmt[input->i] == 'f' || fmt[input->i] == 'F')
		get_float(fmt[input->i], input);
	else if (fmt[input->i] != '\0')
		print_char(input, fmt[input->i]);
}
