/***********************************************************
	select.c -- ‘I‘ð
***********************************************************/
typedef int keytype;

keytype select(keytype a[], int n, int k)
{
	int i, j, left, right;
	keytype x, t;

	left = 0;  right = n - 1;
	while (left < right) {
		x = a[k];  i = left;  j = right;
		for ( ; ; ) {
			while (a[i] < x) i++;
			while (x < a[j]) j--;
			if (i > j) break;
			t = a[i];  a[i] = a[j];  a[j] = t;
			i++;  j--;
		}
		if (j < k) left  = i;
		if (k < i) right = j;
	}
	return a[k];
}

#include <stdio.h>
#include <stdlib.h>

#define N 10
keytype a[N];

int main()
{
	int i, k;

	for (i = 0; i < N; i++) {
		a[i] = rand() / (RAND_MAX / 100 + 1);
		printf(" %d", a[i]);
	}
	printf("\n");
	do {
		printf("¬‚³‚¢•û‚©‚ç”‚¦‚Ä‰½”Ô–Ú‚Ì‚à‚Ì‚ð‹‚ß‚Ü‚·‚©? ");
		scanf("%d", &k);
	} while (k < 1 || k > N);
	printf("  %d”Ô–Ú = %d\n", k, select(a, N, k - 1));
	return EXIT_SUCCESS;
}
