/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:12:56 by jaelee            #+#    #+#             */
/*   Updated: 2018/12/05 19:35:27 by jaelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>


long int add(long int a, long int b)
{
	return (a + b);
}

int main()
{
	int *ptr;
	char s = 10;
	long int d = 100001000000;
	s = (short int)d;
	long double c = 0;
	long double a = 0.0000000000000000000000001;
	unsigned long int as = ULONG_MAX;
	long double zero = 0;
//	printf("%.50Lf\n", a);
//	printf("%zu\n%zu", sizeof(double), sizeof(long double));
	printf("%+x", 255); 
	//printf("%x", -16);
//	printf("%s\n", get_addr((unsigned long long int)a, 16));
//	printf("%d\n", 3/3);
//	printf("%ld\n", (long int)LLONG_MIN);
//	printf("%d\n", i);
//	printf("%ld\n", LONG_MAX);
//	printf("%u\n", UINT_MAX);
//	printf("%d\n", INT_MIN);
//	printf("% .6d", 1);
	return (0);
}
