/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:42:52 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/20 15:24:36 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "bigint.h"
# include "fpoint.h"
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
	mod_L
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
	va_list		ap;
	t_flags		flags;
	t_mod		mod;
	char		*output;
	int			i;
	int			ret;
}				t_pfinfo;

int				ft_printf(const char *fmt, ...);

void			get_flags(const char *fmt, t_pfinfo *input);
void			get_datatype(const char *fmt, t_pfinfo *input);

//number-to-char functions
char			*ltoa(long int n);
char			*ltoa_base(long int n, long int base);

char			*lltoa(long long int n);
char			*lltoa_base(long long int n, long long int base);

char			*ultoa(unsigned long int n);
char			*ultoa_base(unsigned long int n, unsigned long int base);

char			*ulltoa(unsigned long long int n);
char			*ulltoa_base(unsigned long long int n, 
				unsigned long long int base);

/*
** float handling part (include precision processing)
*/
char			*ft_ftoa(t_fprec *nbr);
void			print_float(t_fprec *nbr, t_pfinfo *input);
void			print_integer(t_fprec *nbr, t_pfinfo *input);
void			print_precision(t_fprec *nbr, t_pfinfo *input);
void			print_zerowidth_float(t_pfinfo *input);
void			print_float_error(t_fprec *nbr, t_pfinfo *input);
/*
** utils for printing floats
*/
void			print_sign_float(t_pfinfo *input);
void			check_sign_float(t_pfinfo *input);
void			carry_floats(t_fprec *nbr, t_pfinfo *input);

//get_flags.c - get additional flags before datatypes
void			init_flags(t_flags *flags);
void			get_prec(const char *fmt, t_pfinfo *input);
void			get_width(t_pfinfo *input);
void			get_mod(const char *fmt, t_pfinfo *input);

//process_numeric.c - process %diouxXf
void			get_base(char type, t_pfinfo *input);
void			get_int(t_pfinfo *input);
void			get_uint(t_pfinfo *input);
void			get_float(t_pfinfo *input);

//process_csp.c - process %csp
void			get_chars(char type, t_pfinfo *input);
void			get_strings(char type, t_pfinfo *input);
void			get_addr(t_pfinfo *input);
void			print_addr(t_pfinfo *input);
//base_conversion.c - conversion to other base
void			get_binary(t_pfinfo *input, unsigned long int val);
void			get_octal(t_pfinfo *input, unsigned long int val);
void			get_hexa(t_pfinfo *input, unsigned long int val);

//print_process_nbr.c - process min-wdith and precision and print decimal
//numeric information//
void			print_nbr(t_pfinfo *input);
void			process_precision_nbr(t_pfinfo *input);
void			check_sign_nbr(t_pfinfo *input);
void			print_zerowidth_nbr(t_pfinfo *input);
void			print_sign_nbr(t_pfinfo *input);
//print_process_base.c
void			print_base(char type, t_pfinfo *input);
void			print_hash_base(char type, t_pfinfo *input);
void			process_precision_base(t_pfinfo *input);
void			print_zerowidth_base(char type, t_pfinfo *input);

//init_args.c - load arguments
void			init_int_arg(t_pfinfo *input, long int *val);
void			init_uint_arg(t_pfinfo *input, unsigned long int *val);
void			init_float_arg(t_pfinfo *input, long double *val);

#endif
