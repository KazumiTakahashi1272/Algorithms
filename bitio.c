/***********************************************************
	bitio.c -- Huffman (ハフマン) 法
***********************************************************/

/* Huffman法などで使うビット入出力ルーチン */

#include <stdio.h>
#include <stdlib.h>

FILE *infile, *outfile;      /* 入力ファイル, 出力ファイル */
unsigned long outcount = 0;  /* 出力バイト数カウンタ */
static int getcount = 0, putcount = 8;  /* ビット入出力カウンタ */
static unsigned bitbuf = 0;  /* ビット入出力バッファ */
#define rightbits(n, x) ((x) & ((1U << (n)) - 1U))  /* xの右nビット */

void error(char *message)  /* メッセージを表示し終了 */
{
	fprintf(stderr, "\n%s\n", message);
	exit(EXIT_FAILURE);
}

unsigned getbit(void)  /* 1ビット読む */
{
	if (--getcount >= 0) return (bitbuf >> getcount) & 1U;
	getcount = 7;  bitbuf = getc(infile);
	return (bitbuf >> 7) & 1U;
}

unsigned getbits(int n)  /* nビット読む */
{
	unsigned x;

	x = 0;
	while (n > getcount) {
		n -= getcount;
		x |= rightbits(getcount, bitbuf) << n;
		bitbuf = getc(infile);  getcount = 8;
	}
	getcount -= n;
	return x | rightbits(n, bitbuf >> getcount);
}

void putbit(unsigned bit)  /* 1ビット書き出す */
{
	putcount--;
	if (bit != 0) bitbuf |= (1 << putcount);
	if (putcount == 0) {
		if (putc(bitbuf, outfile) == EOF) error("書けません");
		bitbuf = 0;  putcount = 8;  outcount++;
	}
}

void putbits(int n, unsigned x)  /* nビット書き出す */
{
	while (n >= putcount) {
		n -= putcount;
		bitbuf |= rightbits(putcount, x >> n);
		if (putc(bitbuf, outfile) == EOF) error("書けません");
		bitbuf = 0U;  putcount = 8;  outcount++;
	}
	putcount -= n;
	bitbuf |= rightbits(n, x) << putcount;
}
