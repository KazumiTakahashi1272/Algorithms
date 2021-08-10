/***********************************************************
	change.c -- ¬‘K‚Ì•¥‚¢•û
***********************************************************/

int change(int n, int k)  /* Ä‹A”Å */
{
	int s;

	if (n < 0) return 0;
	s = 1 + n / 5 + change(n - 10, 10);
	if (k >=  50) s += change(n -  50,  50);
	if (k >= 100) s += change(n - 100, 100);
	return s;
}

int change1(int n)  /* ”ñÄ‹A”Å */
{
	int i, j, s, t, u;

	s = 0;
	for (i = n / 100; i >= 0; i--) {     /* 100‰~‹Ê */
		t = n - 100 * i;
		for (j = t / 50; j >= 0; j--) {  /*  50‰~‹Ê */
			u = t - 50 * j;
			s += (1 + u / 5 - u / 10) * (1 + u / 10);
		}
	}
	return s;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;

	printf("‚¨‹à‚Ì•¥‚¢•û\n");
	printf("  ‹àŠz    Ä‹A”Å  ”ñÄ‹A”Å\n");
	for (i = 0; i <= 500; i += 5)
		printf("%6d  %8d  %8d\n", i, change(i, i), change1(i));
	return EXIT_SUCCESS;
}
