#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	int *ptr;
	int b = 1;
	ptr = &b;
	double a;
	a = 1.2;
	//printf("%x", -16);
//	printf("%s\n", get_addr((unsigned long long int)a, 16));
//	printf("%d\n", 3/3);
//	printf("%ld\n", (long int)LLONG_MIN);
	printf("%.5000000000f\n", a);
//	printf("%ld\n", LONG_MAX);
//	printf("%u\n", UINT_MAX);
//	printf("%d\n", INT_MIN);
//	printf("% .6d", 1);
	return (0);
}
