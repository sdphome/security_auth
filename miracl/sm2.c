#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <stdint.h>
#include <sys/time.h>
#include "sm2.h"

#define SM2_PAD_ZERO TRUE
//#define SM2_PAD_ZERO FALSE

#define SM2_DEBUG   0
/*
#define QBITS 256
#define PBITS 3072
#define MAX_ECC_KEY_LEN		256
#define MAX_ECC_KEY_SIZE	(MAX_ECC_KEY_LEN/8)
*/

struct FPECC{
char *p;
char *a;
char *b;
char *n;
char *x;
char *y;
};

#define SECURITY_PACK_HDR_SIZE          5

//7.6.1
typedef struct {
    uint8_t host_rand[8];
    uint8_t sec_rand[8];
    uint64_t serial;
    uint64_t reserve;
    uint8_t sign[64];
    uint8_t x509[0];
} __attribute__ ((packed)) auth_data_param;
#define AUTH_DATA_PARAM_SIZE            96

#if SM2_DEBUG

void PrintBuf(unsigned char *buf, int	buflen) 
{
	int i;
	printf("\n");
	printf("len = %d\n", buflen);
	for(i=0; i<buflen; i++) {
  	if (i % 32 != 31)
  	  printf("%02x", buf[i]);
  	  else
  	  printf("%02x\n", buf[i]);
  }
  printf("\n");
  return;
}
void PrintBig(big data) 
{
 int len=0;
 unsigned char buf[10240];
    
 len=big_to_bytes(0,data,(char *)buf,0);
 PrintBuf(buf,len);
}

unsigned char radom[]  = {0x6C,0xB2,0x8D,0x99,0x38,0x5C,0x17,0x5C,0x94,0xF9,0x4E,0x93,0x48,0x17,0x66,0x3F,0xC1,0x76,0xD9,0x25,0xDD,0x72,0xB7,0x27,0x26,0x0D,0xBA,0xAE,0x1F,0xB2,0xF9,0x6F};
unsigned char radom1[] = {0x4C,0x62,0xEE,0xFD,0x6E,0xCF,0xC2,0xB9,0x5B,0x92,0xFD,0x6C,0x3D,0x95,0x75,0x14,0x8A,0xFA,0x17,0x42,0x55,0x46,0xD4,0x90,0x18,0xE5,0x38,0x8D,0x49,0xDD,0x7B,0x4F};
unsigned char randkey[] = {0x83,0xA2,0xC9,0xC8,0xB9,0x6E,0x5A,0xF7,0x0B,0xD4,0x80,0xB4,0x72,0x40,0x9A,0x9A,0x32,0x72,0x57,0xF1,0xEB,0xB7,0x3F,0x5B,0x07,0x33,0x54,0xB2,0x48,0x66,0x85,0x63};
unsigned char randkeyb[]= {0x33,0xFE,0x21,0x94,0x03,0x42,0x16,0x1C,0x55,0x61,0x9C,0x4A,0x0C,0x06,0x02,0x93,0xD5,0x43,0xC8,0x0A,0xF1,0x97,0x48,0xCE,0x17,0x6D,0x83,0x47,0x7D,0xE7,0x1C,0x80};

struct FPECC Ecc256={
"8542D69E4C044F18E8B92435BF6FF7DE457283915C45517D722EDB8B08F1DFC3",
"787968B4FA32C3FD2417842E73BBFEFF2F3C848B6831D7E0EC65228B3937E498",
"63E4C6D3B23B0C849CF84241484BFE48F61D59A5B16BA06E6E12D1DA27C5249A",
"8542D69E4C044F18E8B92435BF6FF7DD297720630485628D5AE74EE7C32E79B7",
"421DEBD61B62EAB6746434EBC3CC315E32220B3BADD50BDC4C4E6C147FEDD43D",
"0680512BCBB42C07D47349D2153B70C4E5D7FDFCBFA36EA1A85841B9E46E09A2",
};
unsigned char sm2_par_dig[128] = {
0x78,0x79,0x68,0xB4,0xFA,0x32,0xC3,0xFD,0x24,0x17,0x84,0x2E,0x73,0xBB,0xFE,0xFF,
0x2F,0x3C,0x84,0x8B,0x68,0x31,0xD7,0xE0,0xEC,0x65,0x22,0x8B,0x39,0x37,0xE4,0x98,
0x63,0xE4,0xC6,0xD3,0xB2,0x3B,0x0C,0x84,0x9C,0xF8,0x42,0x41,0x48,0x4B,0xFE,0x48,
0xF6,0x1D,0x59,0xA5,0xB1,0x6B,0xA0,0x6E,0x6E,0x12,0xD1,0xDA,0x27,0xC5,0x24,0x9A,
0x42,0x1D,0xEB,0xD6,0x1B,0x62,0xEA,0xB6,0x74,0x64,0x34,0xEB,0xC3,0xCC,0x31,0x5E,
0x32,0x22,0x0B,0x3B,0xAD,0xD5,0x0B,0xDC,0x4C,0x4E,0x6C,0x14,0x7F,0xED,0xD4,0x3D,
0x06,0x80,0x51,0x2B,0xCB,0xB4,0x2C,0x07,0xD4,0x73,0x49,0xD2,0x15,0x3B,0x70,0xC4,
0xE5,0xD7,0xFD,0xFC,0xBF,0xA3,0x6E,0xA1,0xA8,0x58,0x41,0xB9,0xE4,0x6E,0x09,0xA2,
};

#else
/*SM2*/
struct FPECC Ecc256={
"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF",
"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC",
"28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93",
"FFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123",
"32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7",
"BC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0",
};

unsigned char sm2_par_dig[128] = {
0xFF,0xFF,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,
0x28,0xE9,0xFA,0x9E,0x9D,0x9F,0x5E,0x34,0x4D,0x5A,0x9E,0x4B,0xCF,0x65,0x09,0xA7,
0xF3,0x97,0x89,0xF5,0x15,0xAB,0x8F,0x92,0xDD,0xBC,0xBD,0x41,0x4D,0x94,0x0E,0x93,
0x32,0xC4,0xAE,0x2C,0x1F,0x19,0x81,0x19,0x5F,0x99,0x04,0x46,0x6A,0x39,0xC9,0x94,
0x8F,0xE3,0x0B,0xBF,0xF2,0x66,0x0B,0xE1,0x71,0x5A,0x45,0x89,0x33,0x4C,0x74,0xC7,
0xBC,0x37,0x36,0xA2,0xF4,0xF6,0x77,0x9C,0x59,0xBD,0xCE,0xE3,0x6B,0x69,0x21,0x53,
0xD0,0xA9,0x87,0x7C,0xC6,0x2A,0x47,0x40,0x02,0xDF,0x32,0xE5,0x21,0x39,0xF0,0xA0,
};

unsigned char enkey[32] = {
0xB1,0x6B,0xA0,0xDA,0x27,0xC5,0x24,0x9A,0xF6,0x1D,0x6E,0x6E,0x12,0xD1,0x59,0xA5,
0xB6,0x74,0x64,0x34,0xEB,0xD6,0x1B,0x62,0xEA,0xEB,0xC3,0xCC,0x31,0x5E,0x42,0x1D,
};
#endif


#define SEED_CONST 0x1BD8C95A

static void sm2_sign(unsigned char *hash,int hashlen,unsigned char *cr,int *rlen,unsigned char *cs,int *slen)
{
	struct FPECC *cfig = &Ecc256;
    big e, r, s, k;
    big a,b,p,n,x,y,key1;
    epoint *g;
    miracl *mip = mirsys(20, 0);

	char privkey[32] = {0xd4, 0xa0, 0x3d, 0x62, 0xa4, 0xb8, 0xd4, 0x1f, 0x3d, 0xaa,
                    0xd5, 0x02, 0x97, 0xfd, 0x2d, 0xdd, 0xb4, 0x36, 0xdb, 0x18,
                    0xa6, 0x61, 0x4a, 0x3a, 0x88, 0xdf, 0x3a, 0x10, 0x20, 0xbd, 0xb6, 0xc9};

	int privkeylen = 32;

	mip->IOBASE = 16;
	e = mirvar(0); 
	r = mirvar(0); 
	s = mirvar(0);
	k = mirvar(0);

    p = mirvar(0);
	a = mirvar(0);
    b = mirvar(0);
    n = mirvar(0);
    x = mirvar(0);
    y = mirvar(0);

    key1 = mirvar(0);
    bytes_to_big(privkeylen,(char *)privkey,key1);

    cinstr(p,cfig->p);
	cinstr(a,cfig->a);
    cinstr(b,cfig->b);
	cinstr(n,cfig->n);
	cinstr(x,cfig->x);
    cinstr(y,cfig->y);
	ecurve_init(a,b,p,MR_PROJECTIVE);
    g = epoint_init();
    epoint_set(x,y,0,g);
    
	bytes_to_big(hashlen, (char *)hash, e);
    irand(time(NULL)+SEED_CONST);

sm2_sign_again:
#if SM2_DEBUG
	bytes_to_big(32, (char *)radom, k);
#else
	do
	{
		bigrand(n, k);
	}
	while(k->len == 0);
#endif

	ecurve_mult(k, g, g);
	epoint_get(g, r, r);

#if SM2_DEBUG
	PrintBig(r);	
#endif	
	
	add(e, r, r);
	divide(r, n, n);

#if SM2_DEBUG
	PrintBig(r);	
#endif	

	if(r->len == 0) 
		goto sm2_sign_again;

	add(r, k, a);
	if (compare(a, n) == 0) 
		goto sm2_sign_again;
	
	incr(key1, 1, b);
	xgcd(b,n,b,b,b);

#if SM2_DEBUG
	PrintBig(b);	
#endif	
	
	multiply(r, key1, a);
	divide(a, n, n);

	if(compare(k, a) >= 0)
	{
		subtract(k, a, a);
	}
	else
	{
		subtract(n, a, a);
		add(k, a, a);
	}
	
	mad(a,b,a,n,n,s);
#if SM2_DEBUG
	PrintBig(s);	
#endif	
	
    if(s->len == 0) 
		goto sm2_sign_again;

#if SM2_PAD_ZERO
	*rlen = big_to_bytes(32, r, (char *)cr, TRUE);
	*slen = big_to_bytes(32, s, (char *)cs, TRUE);
#else
	*rlen = big_to_bytes(0, r, (char *)cr, FALSE);
	*slen = big_to_bytes(0, s, (char *)cs, FALSE);
#endif	
	mirkill(e);
	mirkill(r); 
	mirkill(s); 
	mirkill(k); 
	mirkill(p);
	mirkill(a); 
	mirkill(b); 
	mirkill(n); 
	mirkill(x); 
	mirkill(y); 
	mirkill(key1);
    epoint_free(g);
	mirexit();
}

//------------------------------------------------------------------------------------------
// For security module

static int file_get_size(const char *path, unsigned long *filesize)
{
	FILE *fp = NULL;

	fp = fopen(path, "r");
	if (fp == NULL) {
		printf("can't open %s.\n", path);
		return -FAILED;
	}

	fseek(fp, 0L, SEEK_END);
	*filesize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	fclose(fp);

	return NO_ERROR;
}

static int file_read_data(uint8_t * buf, FILE * fp, unsigned long size)
{
	int ret = NO_ERROR;
	unsigned long nrd = 0;

	if (fp == NULL || size == 0)
		return -FAILED;

	nrd = fread(buf, size, 1, fp);

	if (nrd < 0) {
		printf("%s: nrd=%ld, size=%ld.\n", __func__, nrd, size);
		ret = -FAILED;
	}

	return ret;
}

static void security_reverse_32(uint8_t * buf)
{
	int i;
	uint8_t temp;

	for (i = 0; i < 16; i ++) {
		temp = buf[i];
		buf[i] = buf[31 - i];
		buf[31 - i] = temp;
	}
}

static int security_digi_sign(auth_data_param * param)
{
	int ret = NO_ERROR;
	uint8_t message[32] = { 0 };
	int rlen, slen;

	memcpy(message, (uint8_t *) & param->host_rand, 8);
	memcpy(message + 8, (uint8_t *) & param->sec_rand, 8);
	memcpy(message + 16, (uint8_t *) & param->serial, 8);
	memcpy(message + 24, (uint8_t *) & param->reserve, 8);
	security_reverse_32(message);

	sm2_sign(message, 32, param->sign, &rlen, param->sign + 32, &slen);

	security_reverse_32(param->sign);
	security_reverse_32(param->sign + 32);

	return ret;
}

/*
	input::
	serial: reader serial
	sec_rand : the rand number which read from security module
	cert_path: x509 certificate path
	data: the data need to send to security module(7.6.1)
	output::
	the valid len of *data, 0 is error.

	Need free the data in the upper level if return not equal 0.
*/
uint16_t security_pack_sign_data(uint64_t serial, uint64_t sec_rand, char * cert_path, uint8_t ** data)
{
	int ret = 0;
	uint16_t len = 0;
	unsigned long size = -1;
	FILE *fp = NULL;
	auth_data_param *param = NULL;

	if (cert_path == NULL)
		return 0;

	ret = file_get_size(cert_path, &size);
	if (ret < 0 || size > 1500 - AUTH_DATA_PARAM_SIZE - SECURITY_PACK_HDR_SIZE) {
		printf("%s: x509 size error, size = %ld.\n", __func__, size);
		return 0;
	}

	param = (auth_data_param *) malloc(AUTH_DATA_PARAM_SIZE + size);
	if (param == NULL) {
		printf("%s: can't malloc memory for param\n", __func__);
		return 0;
	}

	srand((unsigned)time(NULL));
	*(uint64_t *) param->host_rand = (uint64_t) rand() << 32 | (uint64_t) rand();

	memcpy(param->sec_rand, &sec_rand, 8);
	param->serial = serial;
	param->reserve = 0;

	ret = security_digi_sign(param);
	if (ret != 0) {
		free(param);
		printf("%s: sign failed\n", __func__);
		return 0;
	}

	fp = fopen(cert_path, "r");
	if (fp == NULL) {
		printf("read data. fp is null.\n");
		free(param);
		return 0;
	}
	ret = file_read_data(param->x509, fp, size);
	if (ret != NO_ERROR) {
		printf("%s: read x509 failed.\n", __func__);
		fclose(fp);
		free(param);
		return 0;
	}
	fclose(fp);

	*data = (uint8_t *)param;
	return (uint16_t)(AUTH_DATA_PARAM_SIZE + size);
}
