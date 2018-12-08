/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:40:58 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/07 18:25:59 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

static void		get_input(const char *fmt, t_pfinfo *input)
{
	input->i++;
	get_flags(fmt, input);
	get_datatype(fmt, input);
}

int				ft_printf(const char *fmt, ...)
{
	t_pfinfo	input;

	ft_bzero(&input, sizeof(input));
	va_start(input.ap, fmt);
	while (fmt[input.i])
	{
		if (fmt[input.i] == '%' && fmt[input.i + 1] != '%')
			get_input(fmt, &input);
		else if (fmt[input.i] == '%' && fmt[input.i + 1] == '%')
		{
			input.ret += write(1, "%", 1);
			input.i += 2;
		}
		else
		{
			input.ret += write(1, &fmt[input.i], 1);
			input.i++;
		}
	}
	va_end(input.ap);
	return (input.ret);
}

int main()
{
	int a;
	int             bits[64];
	int             i;
	int             tmp;
	unsigned long int    utemp;
	double f = 10;
	i = 63;
	utemp = *(unsigned long int *)&f;
	while (i >= 0)
	{
		bits[i] = utemp & 1;
		utemp = utemp >> 1;
		i--;
	}
/*	while (++i < 64)
	{
		printf("%d", bits[i]);
		if (i == 0)
			printf (" ");
		else if (i == 11)
			printf (" ");
	}*/
	long double l = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
//	ft_printf("%ld\n", UINT_MAX);
	printf("%.10000000000Lf %.1000000000000Lf %.1000000000Lf %.1000000000Lf %.100000000000000Lf %.100000Lf\n", l, l, l, l, l, l);
	return (0);
}	
