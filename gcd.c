/***********************************************************
	gcd.c -- Å‘åŒö–ñ”
***********************************************************/

/* Ä‹A”Å
int gcd(int x, int y)
{
	if (y == 0) return x;
	else        return gcd(y, x % y);
}
*/

/* ”ñÄ‹A”Å */
int gcd(int x, int y)
{
	int t;

	while (y != 0) {
		t = x % y;  x = y;  y = t;
	}
	return x;
}

/* a[0], ..., a[n-1] ‚Ì”‚ÌÅ‘åŒö–ñ” */
int ngcd(int n, int a[])
{
	int i, d;

	d = a[0];
	for (i = 1; i < n && d != 1; i++)
		d = gcd(a[i], d);
	return d;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char s[2];
	static int a[100];

	for ( ; ; ) {
		printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ");
		for (i = 0; i < 100; i++) {
			if (scanf("%*[^0123456789\n]%1[\n]", &s) == 1) break;
			if (scanf("%d", &a[i]) != 1) break;
		}
		if (i == 0) break;
		printf("Å‘åŒö–ñ” = %d\n", ngcd(i, a));
	}
	return EXIT_SUCCESS;
}
