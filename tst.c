/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:12:56 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/01 23:07:01 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int *ptr;
	short int s = -32768;
	int i;
	
	i = (int)s;

	//printf("%x", -16);
//	printf("%s\n", get_addr((unsigned long long int)a, 16));
//	printf("%d\n", 3/3);
//	printf("%ld\n", (long int)LLONG_MIN);
	printf("%d\n", i);
//	printf("%ld\n", LONG_MAX);
//	printf("%u\n", UINT_MAX);
//	printf("%d\n", INT_MIN);
//	printf("% .6d", 1);
	return (0);
}
