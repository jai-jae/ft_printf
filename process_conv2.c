/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_conv2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 12:24:31 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/28 15:45:40 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	get_addr(t_pfinfo *input)
{
	unsigned long int val;

	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	val = va_arg(input->ap, unsigned long int);
	if (input->flags.prec == 0)
		input->output = ft_strdup("\0");
	else
		input->output = ultoa_base(val, 16);
	if (!input->output)
		return ;
	ft_strlower(input->output);
	print_addr(input);
}

void	get_chars(char type, t_pfinfo *input)
{
	unsigned char	ch;
	char			*str;

	input->flags.minus == 1 ? input->flags.zero = 0 : 0;
	if (type == 's')
	{
		str = (char*)va_arg(input->ap, char*);
		if (str == NULL)
			return (print_null_str(input));
		if (!(input->output = ft_strdup(str)))
			return ;
		print_str(input);
	}
	else if (type == 'c')
	{
		ch = (unsigned char)va_arg(input->ap, int);
		print_char(input, ch);
	}
}

void	get_percent(t_pfinfo *input)
{
	if (input->flags.minus == 1)
	{
		input->ret += write(1, "%", 1);
		while (input->flags.width-- > 1)
			input->ret += write(1, " ", 1);
	}
	else
	{
		while (input->flags.width-- > 1)
			input->ret += (input->flags.zero ?
					write(1, "0", 1) : write(1, " ", 1));
		input->ret += write(1, "%", 1);
	}
	input->i++;
}
