/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bigint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:40:08 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/08 18:16:29 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "bigint.h"
#include "../libft/libft.h"

int	main()
{
	unsigned int a = 4294967295;
	unsigned int b = 4;
	t_bigint bg1;
	t_bigint bg2;
	t_bigint bg3;
	ft_create_bigint(2, &bg1);
	ft_create_bigint(2, &bg2);
	ft_create_bigint(4, &bg3);
	ft_initsmall_bigint(&bg1, a);
	ft_initsmall_bigint(&bg2, 2);
	ft_mul_small(&bg1, 2);
	printf("bg1[0] = %u\n", bg1.data[0]);
	printf("bg2[0] = %u\n", bg2.data[0]);
	printf("ans[0] = %u\n", bg1.data[0]);
	printf("ans[0] = %u\n", bg1.data[1]);	
	printf("ans[0] = %u\n", bg1.data[2]);
	printf("ans[0] = %u\n", bg1.data[3]);
	return (0);
}
