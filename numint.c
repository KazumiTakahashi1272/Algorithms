/***********************************************************
	numint.c -- ”’lÏ•ª
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

double f(double x)  /* ”íÏ•ªŠÖ” $f(x)$ */
{
	return 4 / (1 + x * x);  /* —á $4 / (1 + x^2)$ */
}

int main()
{
	int i, n, nmax = 32;
	double a = 0, b = 1, h, trapezoid, midpoint, simpson;

	printf("    n  ‘äŒ`           ’†“_           Simpson\n");
	h = b - a;  trapezoid = h * (f(a) + f(b)) / 2;
	for (n = 1; n <= nmax; n *= 2) {
		midpoint = 0;
		for (i = 1; i <= n; i++) midpoint += f(a + h * (i - 0.5));
		midpoint *= h;
		simpson = (trapezoid + 2 * midpoint) / 3;
		printf("%5d % -14g % -14g % -14g\n",
			n, trapezoid, midpoint, simpson);
		h /= 2;  trapezoid = (trapezoid + midpoint) / 2;
	}
	return EXIT_SUCCESS;
}
