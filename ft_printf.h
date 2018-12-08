/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:42:52 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/08 17:19:20 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "./libft/libft.h"
# define BASE "boxX"
# define FLAGS "#0-+ *.123456789hlL"
# define NBR "0123456789"

typedef enum	e_mod
{
	mod_non = 0,
	mod_l,
	mod_ll,
	mod_h,
	mod_hh,
	mod_L,
}				t_mod;

typedef struct	s_flags
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		prec;
	int		neg;
}				t_flags;

typedef struct	s_pfinfo
{
	va_list ap;
	t_flags	flags;
	t_mod	mod;
	char	*output;
	int		i;
	int		ret;
}				t_pfinfo;

int		ft_printf(const char *fmt, ...);

void	get_flags(const char *fmt, t_pfinfo *input);
void	get_datatype(const char *fmt, t_pfinfo *input);

//number-to-char functions
char	*ltoa(long int n);
char	*ltoa_base(long int n, long int base);

char	*lltoa(long long int n);
char	*lltoa_base(long long int n, long long int base);

char	*ultoa(unsigned long int n);
char	*ultoa_base(unsigned long int n, unsigned long int base);

char	*ulltoa(unsigned long long int n);
char	*ulltoa_base(unsigned long long int n, unsigned long long int base);

//float_manipulation.c - float printing part (include precision processing)
char	*ftoa(long double d);

//get_flags.c - get additional flags before datatypes
void	get_prec(const char *fmt, t_pfinfo *input);
void	get_width(const char *fmt, t_pfinfo *input);
void	get_mod(const char *fmt, t_pfinfo *input);

//process_numeric.c - process %diouxXf
void	get_base(char type, t_pfinfo *input);
void	get_int(char type, t_pfinfo *input);
void	get_uint(char type, t_pfinfo *input);
void	get_float(char type, t_pfinfo *input);

//process_csp.c - process %csp
void	get_char(char type, t_pfinfo *input);
void	get_strings(char type, t_pfinfo *input);
void	get_addr(char type, t_pfinfo *input);

//base_conversion.c - conversion to other base
void	get_binary(t_pfinfo *input, unsigned long int val);
void	get_octal(t_pfinfo *input, unsigned long int val);
void	get_hexa(t_pfinfo *input, unsigned long int val);

//print_process_nbr.c - process min-wdith and precision and print decimal
//numeric information//
void	print_nbr(t_pfinfo *input);
void	process_precision_nbr(t_pfinfo *input);
void	check_sign_nbr(t_pfinfo *input);
void	print_zerowidth_nbr(t_pfinfo *input);
void	print_sign_nbr(t_pfinfo *input);
//print_process_base.c
void	print_base(char type, t_pfinfo *input);
void	print_hash_base(char type, t_pfinfo *input);
void	process_precision_base(char type, t_pfinfo *input);
void	print_zerowidth_base(char type, t_pfinfo *input);

//init_args.c - load arguments
void	init_int_arg(t_pfinfo *input, long int *val);
void	init_uint_arg(t_pfinfo *input, unsigned long int *val);
void	init_float_arg(t_pfinfo *input, long double *val);
#endif
