/***********************************************************
	water.c -- …‚ğ‚Í‚©‚é–â‘è
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)  /* Å‘åŒö–ñ” */
{
	if (x == 0) return y;  else return gcd(y % x, x);
}

int main()
{
	int a, b, v, x, y;

	printf("—eŠí‚`‚Ì—eÏ? ");  scanf("%d", &a);
	printf("—eŠí‚a‚Ì—eÏ? ");  scanf("%d", &b);
	printf("‚Í‚©‚è‚½‚¢—eÏ? ");  scanf("%d", &v);
	if (v > a && v > b || v % gcd(a, b) != 0) {
		printf("‚Í‚©‚ê‚Ü‚¹‚ñ\n");  return EXIT_FAILURE;
	}
	x = y = 0;
	do {
		if (x == 0) {
			printf("‚`‚É…‚ğ–‚½‚µ‚Ü‚·\n");  x = a;
		} else if (y == b) {
			printf("‚a‚ğ‹ó‚É‚µ‚Ü‚·\n");  y = 0;
		} else if (x < b - y) {
			printf("‚`‚Ì…‚ğ‚·‚×‚Ä‚a‚ÉˆÚ‚µ‚Ü‚·\n");
			y += x;  x = 0;
		} else {
			printf("‚`‚Ì…‚ğ‚a‚ª‚¢‚Á‚Ï‚¢‚É‚È‚é‚Ü‚Å"
				"‚a‚ÉˆÚ‚µ‚Ü‚·\n");  x -= b - y;  y = b;
		}
	} while (x != v && y != v);
	if      (x == v) printf("‚`‚É‚Í‚©‚ê‚Ü‚µ‚½\n");
	else if (y == v) printf("‚a‚É‚Í‚©‚ê‚Ü‚µ‚½\n");
	return EXIT_SUCCESS;
}
