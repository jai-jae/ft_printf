/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:31:14 by jaelee            #+#    #+#             */
/*   Updated: 2019/01/07 00:42:44 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPOINT_H
# define FPOINT_H
# define BCD_SIZE 12000
# define MIN_64 -1023
# define MAX_64 1024
# define MIN_80 -16383
# define MAX_80 16384
# include <stdint.h>
# include <stdlib.h>
# include "bigint.h"

typedef enum	e_error
{
	ft_nan = 0,
	ft_inf,
	ft_zero
}				t_error;

typedef struct	s_fprec
{
	int				ext;
	uint64_t		mantissa;
	uint64_t		sign;
	int				exp;
	int				len_sosu;
	int				diff_sosu_exp;
	int				diff_exp_sosu;
	t_bigint		bg;
	t_error			err;
	int				dot;
}				t_fprec;

/*
** double -> bigint functions
*/
void			init_bigint(t_fprec *nbr);
void			init_fprec(t_fprec *nbr);
int				process_bigint(t_fprec *nbr);
int				handle_strange(t_fprec *nbr);
int				float_64(double d, t_fprec *nbr);
int				float_80(long double d, t_fprec *nbr);
int				handle_error64(t_fprec *nbr);
int				handle_error80(t_fprec *nbr);

/*
** double dabble algorithm binary -> BCD
*/
unsigned char	*double_dabble(t_fprec *nbr, unsigned char *bcd);
unsigned char	*process_output(t_fprec *nbr, unsigned char *bcd, int sig_len);
#endif
