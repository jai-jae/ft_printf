/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:45:31 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/16 16:20:09 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H
# define BCD_SIZE 1024
# include <stdint.h>
# include "../../libft/libft.h"


typedef struct	s_bigint
{
	uint32_t	len;
	uint32_t	*data;
}				t_bigint;

typedef struct	s_fprec
{
	uint64_t		mantissa;
	uint64_t		sign;
	int				exp;
	int				len_sosu;
	t_bigint		bg;
	unsigned char	bcd[BCD_SIZE];
}				t_fprec;
/*
** BIGINT manipulating functions
*/
uint32_t		ft_create_bigint(uint32_t len, t_bigint *bg);
void			ft_del_biging(t_bigint *bg);
void			ft_initsmall_bigint(t_bigint *dst, uint32_t val);
void			ft_initbig_bigint(t_bigint *dst, t_bigint *src);
void			ft_add_bigint(t_bigint *dst, t_bigint *src);
void			ft_add_small_pos(t_bigint *dst, uint32_t val, uint32_t pos);
void			ft_mul_big(t_bigint *dst, t_bigint *a, t_bigint *b);
void			ft_mul_small(t_bigint *dst, uint32_t val);
void			ft_shiftr_bigint(t_bigint *dst, uint32_t val);
void			ft_shiftl_bigint(t_bigint *dst, uint32_t val);
/*
** double -> bigint functions
*/
void			init_bigint(t_fprec *nbr);
void			init_fprec(t_fprec *nbr);
void			process_bigint(t_fprec *nbr);
int				handle_strange(t_fprec *nbr);
int				ft_ftoa64(double d);
int				init_mantissa64(double d, t_fprec *nbr);

/*
** double dabble algorithm binary -> BCD
*/
void			double_dabble(t_fprec *nbr);
#endif
