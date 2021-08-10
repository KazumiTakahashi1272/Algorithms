/***********************************************************
	tree.c -- 2•ª’Tõ–Ø
***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char keytype[21];

typedef struct node {
	struct node *left, *right;
	keytype key;
} *nodeptr;

struct node nil;
nodeptr root = &nil;

nodeptr insert(keytype key)  /* ‘}“ü (“o˜^) */
{
	int cmp;
	nodeptr *p, q;

	strcpy(nil.key, key);  /* ”Ôl */
	p = &root;
	while ((cmp = strcmp(key, (*p)->key)) != 0)
		if (cmp < 0) p = &((*p)->left );
		else         p = &((*p)->right);
	if (*p != &nil) return NULL;  /* ‚·‚Å‚É“o˜^‚³‚ê‚Ä‚¢‚é */
	if ((q = malloc(sizeof *q)) == NULL) {
		printf("ƒƒ‚ƒŠ•s‘«.\n");  exit(EXIT_FAILURE);
	}
	strcpy(q->key, key);
	q->left = &nil;  q->right = *p;  *p = q;
	return q;  /* “o˜^‚µ‚½ */
}

int delete(keytype key)  /* íœ‚Å‚«‚ê‚Î 0, ¸”s‚È‚ç 1 ‚ğ•Ô‚· */
{
	int cmp;
	nodeptr *p, *q, r, s;

	strcpy(nil.key, key);  /* ”Ôl */
	p = &root;
	while ((cmp = strcmp(key, (*p)->key)) != 0)
		if (cmp < 0) p = &((*p)->left);
		else         p = &((*p)->right);
	if (*p == &nil) return 1;  /* Œ©‚Â‚©‚ç‚¸ */
	r = *p;
	if      (r->right == &nil) *p = r->left;
	else if (r->left  == &nil) *p = r->right;
	else {
		q = &(r->left);
		while ((*q)->right != &nil) q = &((*q)->right);
		s = *q;  *q = s->left;
		s->left = r->left;  s->right = r->right;
		*p = s;
	}
	free(r);
	return 0;  /* íœ¬Œ÷ */
}

nodeptr search(keytype key)  /* ŒŸõ (–¢“o˜^‚È‚çNULL‚ğ•Ô‚·) */
{
	int cmp;
	nodeptr p;

	strcpy(nil.key, key);  /* ”Ôl */
	p = root;
	while ((cmp = strcmp(key, p->key)) != 0)
		if (cmp < 0) p = p->left;
		else         p = p->right;
	if (p != &nil) return p;     /* Œ©‚Â‚©‚Á‚½ */
	else           return NULL;  /* Œ©‚Â‚©‚ç‚È‚¢ */
}

void printtree(nodeptr p)
{
	static int depth = 0;

	if (p->left != &nil) {
		depth++;  printtree(p->left);  depth--;
	}
	printf("%*c%s\n", 5 * depth, ' ', p->key);
	if (p->right != &nil) {
		depth++;  printtree(p->right);  depth--;
	}
}

int main()
{
	char buf[22];

	printf("–½—ß Iabc:  abc‚ğ‘}“ü\n"
		   "     Dabc:  abc‚ğíœ\n"
		   "     Sabc:  abc‚ğŒŸõ\n");
	for ( ; ; ) {
		printf("–½—ß? ");
		if (scanf("%21s%*[^\n]", buf) != 1) break;
		switch (buf[0]) {
		case 'I':  case 'i':
			if (insert(&buf[1])) printf("“o˜^‚µ‚Ü‚µ‚½.\n");
			else                 printf("“o˜^‚¸‚İ‚Å‚·.\n");
			break;
		case 'D':  case 'd':
			if (delete(&buf[1])) printf("“o˜^‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ.\n");
			else                 printf("íœ‚µ‚Ü‚µ‚½.\n");
			break;
		case 'S':  case 's':
			if (search(&buf[1])) printf("“o˜^‚³‚ê‚Ä‚¢‚Ü‚·.\n");
			else                 printf("“o˜^‚³‚ê‚Ä‚¢‚Ü‚¹‚ñ\n");
			break;
		default:
			printf("g‚¦‚é‚Ì‚Í I, D, S ‚Å‚·.\n");
			break;
		}
		if (root != &nil) {
			printf("\n");  printtree(root);  printf("\n");
		}
	}
	return EXIT_SUCCESS;
}
