/***********************************************************
	list1.c -- ÉäÉXÉg
***********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define NIL 100  /* ç≈ëÂÇÃìYéö + 1 */
typedef int indextype, infotype;

infotype info[NIL];
indextype next[NIL];

indextype add_list(infotype x, indextype p)
{
	static indextype avail = 0;
	indextype q;

	q = avail++;
	if (q == NIL) {
		printf("ñûîtÇ≈Ç∑.\n");  exit(EXIT_FAILURE);
	}
	info[q] = x;  next[q] = p;
	return q;
}

void show_list(indextype p)
{
	while (p != NIL) {
		printf(" %d", info[p]);  p = next[p];
	}
	printf("\n");
}

indextype reverse_list(indextype p)
{
	indextype q, t;

	q = NIL;
	while (p != NIL) {
		t = q;  q = p;  p = next[p];  next[q] = t;
	}
	return q;
}

int main()
{
	infotype x;
	indextype head;

	head = NIL;                             /* ãÛÇÃÉäÉXÉg */
	for (x = 1; x <= 9; x++)
		head = add_list(x, head);                 /* ìoò^ */
	show_list(head);                              /* ï\é¶ */
	head = reverse_list(head);        /* ãtèáÇ…ï¿Ç◊ë÷Ç¶ÇÈ */
	show_list(head);                              /* ï\é¶ */
	return EXIT_SUCCESS;
}
