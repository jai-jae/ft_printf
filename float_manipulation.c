/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:55:55 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/04 20:06:07 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //test please erase when finished

char	*float_output(char *val, int dot, int end)
{
	char *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = ft_strnew(ft_strlen(val) + 1);
	while (val[i] != '\0')
	{
		tmp[j++] = val[i];
		if (i == dot - 1 && end > 0)
			tmp[j++] = '.';
		if (i >= end)
		{
			tmp[j] = '\0';
			break;
		}
		i++;
	}
	return (tmp);
}

long	float_to_int(long double d, int prec)
{
	int neg;
	int	i;

	i = 0;
	neg = d < 0 ? -1 : 1;
	d *= neg;
	while (i < prec)
	{
		d *= 10;
		i++;
	}
	d += 0.5; //for rounding up those over 0.5
	d *= neg;
	return ((long int)d);
}

char	*ft_ftoa(long double d)
{
	char *val;
	long int tmp;
	int	len;
	int neg;
	int i = 0;
	neg = d < 0 ? -1 : 1;
	len = d < 0 ? 1 : 0;
	d *= neg;
	tmp = (long int)d;
	while (tmp > 0 && len++ >= 0)
		tmp /= 10;
	ft_putstr("what the hell\n");
	printf("before : %.50Lf\n", d);
/*	while (d - (long int)d != 0 && len++ >= 0)
	{
		ft_putstr("what the fuck\n");
		d *= 10;
	}*/
	printf("after : %Lf\n", d);
	val = ft_strnew(len);
	while (--len >= 0)
	{
		val[len] = (long int)d % 10 + '0';
		d /= 10;
		if (neg == -1 && len == 1)
		{
			val[0] = '-';
			break ;
		}
	}
	return (val);
}

void	process_float(t_pfinfo *input, long double d)
{
	char *tmp;
	char *val;
	long num;
	int	idigit;

	tmp = ltoa((long int)d);
	idigit = ft_strlen(tmp); //how many digit is the integer
	num = float_to_int(d, (input->flags.prec >= 0 ? input->flags.prec : 6));
	val = (num == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	if (input->flags.prec == 0)
		input->output = ft_strdup(tmp);
	else (input->flags.prec + idigit < 18)
		input->output = float_output(val, idigit, input->flags.prec >= 0 ?
		idigit + input->flags.prec : idigit + 6);
	else
		input->output = float_output(val, idigit, 17);
	free(val);
	free(tmp);
}

int main()
{
	long double a;
	long num;
	char *nb;
	char *out;
	a = 123.123123123123123123123;

	num = float_to_int(a, 14);
	//printf("%ld\n", num);
	nb = ft_ftoa(num);
	//printf("%s\n", nb);
	out = float_output(nb, 4, 13);
	printf("%s\n", out);
	return (0);
}
