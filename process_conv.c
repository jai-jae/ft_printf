/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:50:17 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 20:09:30 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_datatype(const char *fmt, t_pfinfo *input)
{
	if (ft_strchr(HEX, fmt[input->i])
		process_base(fmt, input);
	else if (fmt[input->i] == 'd' || fmt[input->i] == 'i')
		process_int(fmt, input);
	else if (fmt[input->i] == 'u')
		process_uint(fmt, input);
	else if	(fmt[input->i] == 'c')
		process_chars(fmt, input);
	else if (fmt[input->i] == 's')
		process_strings(fmt[input->i], input);
	else if (fmt[input->i] == 'p')
		process_addr(fmt, input);
	else if (fmt[input->i] == 'f')
		process_float(fmt, input);
}

void	process_base(const char *fmt, t_pfinfo *input)
{
		char					type;
		unsigned int			val;
		unsigned long int		tmp;

		val = 0;
		type = fmt[input->i];
		//TODO init_nbr_arg(input, &tmp)
		//TODO tmp = (casting)va_arg(input->i, DATA_TYPE);
		if (input->mod == mod_l || input->mod == mod_h || input->mod == mod_hh)
			(unsigned long int)val = tmp;
		else if (input->mod == mod_ll)
			(unsigned long long int)val = tmp;
		else if (input->mod == mod_h)
			(unsigned short int)val = tmp;
		else if (input->mod == mod_hh)
			(unsigned char)val = tmp;
		else if (input->mod == mod_non)
			(unsigned int)val = tmp;
		if (type == 'o')
			input->output = ultoa_base(val, 8);
		else if (type == 'X' || type == 'x')
			input->output = ultoa_base(val, 16);
		if (type == 'X')
			ft_str_tolower(input->output);
		print_base(input, val);
}

void	process_int(const char *fmt, t_pfinfo *input)
{
	char		type;
	long int	val;
	long int	tmp;

	val = 0;
	type = fmt[input->i];
	//TODO tmp = (casting)va_arg(input->i, DATA_TYPE);
	if (input->mod == mod_hh ||

