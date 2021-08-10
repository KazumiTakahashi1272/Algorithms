/***********************************************************
	hanoi.c -- ƒnƒmƒC‚Ì“ƒ
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

void movedisk(int n, int a, int b)
{
	if (n > 1) movedisk(n - 1, a, 6 - a - b);
	printf("‰~”Õ %d ‚ğ %d ‚©‚ç %d ‚ÉˆÚ‚·\n", n, a, b);
	if (n > 1) movedisk(n - 1, 6 - a - b, b);
}

int main()
{
	int n;

	printf("‰~”Õ‚Ì–‡”? ");  scanf("%d", &n);
	printf("‰~”Õ %d –‡‚ğ’Œ 1 ‚©‚ç’Œ 2 ‚ÉˆÚ‚·•û–@‚Í"
		"Ÿ‚Ì %lu è‚Å‚·.\n", n, (1UL << n) - 1);
	movedisk(n, 1, 2);
	return EXIT_SUCCESS;
}
