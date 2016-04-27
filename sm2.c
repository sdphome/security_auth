#include <stdio.h>
#include <stdlib.h>

void sm2_sign(unsigned char *data, int datalen,	unsigned char *sA, int *Alen, unsigned char *sB, int *Blen);

int main()
{
	unsigned char data[]={"12345678123456781234567812345678"};
	unsigned char sign_A[32]={};
	int sign_A_len;
	unsigned char sign_B[32]={};
	int    sign_B_len;


	sm2_sign(data, 32, sign_A, &sign_A_len, sign_B, &sign_B_len);

	return 0;
}
