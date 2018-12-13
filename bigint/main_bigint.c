/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bigint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:40:08 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/13 14:35:16 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "bigint.h"
#include "../../libft/libft.h"

int	main()
{
	unsigned int a = 0xffffffff;
	unsigned int b = 0x0000000f;
	t_bigint bg1;
	t_bigint bg2;
	t_bigint bg3;
	ft_create_bigint(5, &bg1);
	ft_create_bigint(5, &bg2);
	ft_create_bigint(4, &bg3);
	ft_initsmall_bigint(&bg1, a);
	ft_add_small_pos(&bg1, 0x1f, 1);
//	ft_initsmall_bigint(&bg2, b);
//	ft_mul_small(&bg1, 3);
	printf("bg1[0] = %u\n", bg1.data[0]);
	printf("bg1[1] = %u\n", bg1.data[1]);
	ft_shiftl_bigint(&bg1, 1);
	printf("bg1[0] = %u\n", bg1.data[0]);
	printf("bg1[1] = %u\n", bg1.data[1]);


	return (0);
}
