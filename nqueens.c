/***********************************************************
	nqueens.c -- Nâ§î‹ÇÃñ‚ëË
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define N  8  /* NÅ~N ÇÃî’ñ  */
int a[N], b[2 * N - 1], c[2 * N - 1], x[N];

void found(void)
{
	int i, j;
	static solution = 0;

	printf("\nâ %d\n", ++solution);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			if (x[i] == j) printf(" Q");
			else           printf(" .");
		printf("\n");
	}
}

void try(int i)
{
	int j;

	for (j = 0; j < N; j++)
		if (a[j] && b[i + j] && c[i - j + N - 1]) {
			x[i] = j;
			if (i < N - 1) {
				a[j] = b[i + j] = c[i - j + N - 1] = 0;
				try(i + 1);
				a[j] = b[i + j] = c[i - j + N - 1] = 1;
			} else found();
		}
}

int main()
{
	int i;

	for (i = 0; i < N; i++)         a[i] = 1;
	for (i = 0; i < 2 * N - 1; i++) b[i] = 1;
	for (i = 0; i < 2 * N - 1; i++) c[i] = 1;
	try(0);
	return EXIT_SUCCESS;
}
