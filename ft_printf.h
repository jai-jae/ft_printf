/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:42:52 by jaelee            #+#    #+#             */
/*   Updated: 2018/11/30 23:07:42 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"
# define HEX "xX";
# define FLAGS "#0-+ *.123456789hlL";
# define NBR "0123456789";

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
}				t_flags;

typedef struct	s_pfinfo
{
	va_list ap[2];
	t_flags	flags;
	t_mod	mod;
	char	*output;
	int		i;
	int		ret;
}				t_pfinfo;

int		ft_printf(const char *format, ...);
int		ft_str_tolower(int c); //TODO make one
int		ft_atoi(const char* str);

char	*itoa(int n, long int base);
char	*itoa_base(int n, long int base);

char	*ltoa(long int n, unsigned long int base); //TODO cast negative nbr as 'unsigned' PLEASE!'
char	*ltoa_base(long int n, unsigned long int base);

char	*uitoa(unsigned int n, unsigned int base);
char	*uitoa_base(unsigned int n, unsigned int base);

char	*ultoa(unsigned long int n, unsigned long int base);
char	*ultoa_base(unsigned long int n, unsigned long int base);
//TODO lltoas
char	*lltoa(long long int n, unsigned long long int  base);
char	*lltoa_base(long long int n, unsigned long long int base);

char	*ulltoa(long long int n, unsigned long long int base);
char	*ulltoa_base(long long int, unsigned long long int base);
//TODO ftoa : structure of two ints - one for integer and one for decimal
char	*ftoa(long double);
char	*get_addr(unsigned long int n, unsigned long int base);
char	*ft_strchr(); //TODO may need it;
//TODO getchar, getstr print_output + all different flags;
#endif
