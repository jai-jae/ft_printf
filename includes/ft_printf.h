/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:42:52 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/07 00:29:08 by jaelee           ###   ########.fr       */
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
# define FLAGS "#0-+ *.123456789hlLjz"
# define NBR "0123456789"

typedef enum	e_mod
{
	mod_non = 0,
	mod_l,
	mod_ll,
	mod_h,
	mod_hh,
	mod_j,
	mod_z,
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
	char		*bf;
	int			i;
	int			fd;
	int			ret;
}				t_pfinfo;

int				ft_printf(const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);
void			get_flags(const char *fmt, t_pfinfo *e);
void			get_datatype(const char *fmt, t_pfinfo *e);

char			*ltoa(long int n);
char			*ltoa_base(long int n, long int base);
char			*lltoa(long long int n);
char			*lltoa_base(long long int n, long long int base);
char			*ultoa(unsigned long int n);
char			*ultoa_base(unsigned long int n, unsigned long int base);
char			*ulltoa(unsigned long long int n);
char			*ulltoa_base(unsigned long long int n,
		unsigned long long int base);

char			*ft_ftoa(t_fprec *nbr);
void			print_float(t_fprec *nbr, t_pfinfo *e);
void			print_integer(t_fprec *nbr, t_pfinfo *e);
void			print_precision(t_fprec *nbr, t_pfinfo *e);
void			print_zerowidth_float(t_pfinfo *e);
void			print_float_error(char type, t_fprec *nbr, t_pfinfo *e);

void			print_sign_float(t_pfinfo *e);
void			check_sign_float(t_pfinfo *e);
void			carry_floats(t_fprec *nbr, t_pfinfo *e);

void			init_flags(t_pfinfo *e);
void			get_prec(const char *fmt, t_pfinfo *e);
void			get_width(t_pfinfo *e);
void			get_mod(const char *fmt, t_pfinfo *e);
void			get_base(char type, t_pfinfo *e);
void			get_int(t_pfinfo *e);
void			get_uint(char type, t_pfinfo *e);
void			get_float(char type, t_pfinfo *e);
void			get_chars(char type, t_pfinfo *e);
void			get_strings(char type, t_pfinfo *e);
void			get_addr(t_pfinfo *e);
void			get_percent(t_pfinfo *e);
void			get_binary(t_pfinfo *e, unsigned long int val);
void			get_octal(t_pfinfo *e, unsigned long int val);
void			get_hexa(t_pfinfo *e, unsigned long int val);

void			print_nbr(t_pfinfo *e);
void			process_precision_nbr(t_pfinfo *e);
void			check_sign_nbr(t_pfinfo *e);
void			print_zerowidth_nbr(t_pfinfo *e);
void			print_sign_nbr(t_pfinfo *e);

void			print_base(char type, t_pfinfo *e);
void			print_hash_base(char type, t_pfinfo *e);
void			process_precision_base(t_pfinfo *e);
void			print_zerowidth_base(char type, t_pfinfo *e);

void			print_addr(t_pfinfo *e);
int				addr_precision(t_pfinfo *e);
void			print_width_addr(t_pfinfo *e);

void			init_int_arg(t_pfinfo *e, long int *val);
void			init_uint_arg(char type, t_pfinfo *e,
				unsigned long int *val);

void			print_null_str(t_pfinfo *e);
void			print_str(t_pfinfo *e);
void			print_zerowidth_str(t_pfinfo *e);

void			print_char(t_pfinfo *e, unsigned char ch);
void			print_zerowidth_char(t_pfinfo *e);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_itoa_base(int n, long int base);
char			*ft_uitoa(unsigned int n);
char			*ft_uitoa_base(unsigned int n, unsigned int base);
void			ft_strlower(char *str);
void			ft_strupper(char *str);

#endif
