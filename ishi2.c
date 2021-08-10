/***********************************************************
	ishi2.c -- Îæ‚èƒQ[ƒ€ 2
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, max, n, x, f[21], r, my_turn;

	f[1] = f[2] = 1;
	for (i = 3; i <= 20; i++) f[i] = f[i - 1] + f[i - 2];
	printf("Î‚Ì” (2..10000)? ");  scanf("%d", &n);
	if (n < 2 || n > 10000) return EXIT_FAILURE;
	max = n - 1;
	for (my_turn = 1; n != 0; my_turn ^= 1) {
		printf("%d ŒÂ‚Ü‚Åæ‚ê‚Ü‚·.\n", max);
		if (my_turn) {
			x = n;
			for (i = 20; x != f[i]; i--) if (x > f[i]) x -= f[i];
			if (x > max) x = 1;
			printf("„‚Í %d ŒÂ‚ÌÎ‚ğ‚Æ‚è‚Ü‚·.\n", x);
		} else do {
			printf("‰½ŒÂ‚Æ‚è‚Ü‚·‚©? ");
			r = scanf("%d", &x);  scanf("%*[^\n]");
		} while (r != 1 || x < 1 || x > max);
		n -= x;  max = 2 * x;  if (max > n) max = n;
		printf("c‚è‚Í %d ŒÂ‚Å‚·.\n", n);
	}
	if (my_turn) printf("‚ ‚È‚½‚ÌŸ‚¿‚Å‚·!\n");
	else         printf("„‚ÌŸ‚¿‚Å‚·!\n");
	return EXIT_SUCCESS;
}
