/**************************************************************************
Filename	: types.hpp
Language	: C header file
Description	: Define variable types
Author(s)	:   
Company		: ANCH Ltd.
version 	: 1.0
Change Log	: 2007-3-1 11:04, first edition
******************************************************************************/


#ifndef TYPES_H
#define TYPES_H
/**************************************************************************/
//#ifndef WIN32

/* other stuff... */
#define	STRNCPY(a,b,c)		strncpy (a,b,c); (*((a)+(c)) = 0x00);


/**************************************************************************
STANDARD TYPEDEFS

The ANSI C std defines:
	short <= int <= long
	char >= 8 bits
	short >= 16 bits
	long >= 32 bits
	(from Harbison & Steele, "C, A Ref. Manual" 3rd ed. p. 99)

	so all ANSI C compliant compilers will accept the following.
**************************************************************************/
/* define 8 bit types */
typedef unsigned char		UINT8;
typedef  unsigned char        u_char;
typedef  unsigned char        uchar;
typedef signed char			SINT8;

/* define 16 bit types */
typedef unsigned short		UINT16;
typedef unsigned short		u_short;
typedef signed short		SINT16;

/* define 32 bit types */
typedef unsigned long 		UINT_32;
typedef unsigned long 		u_long;
typedef signed long 		SINT32;


typedef char			CHAR;	/* be careful of EOF!!! (EOF = -1) */

typedef int 		BOOL;

typedef signed long 		TIME_T;

typedef float				SINGLE;
#ifdef	DOUBLE
#undef	DOUBLE
#endif
typedef double				DOUBLE;

typedef struct
{
  unsigned bit0 : 1;
  unsigned bit1 : 1;
  unsigned bit2 : 1;
  unsigned bit3 : 1;
  unsigned bit4 : 1;
  unsigned bit5 : 1;
  unsigned bit6 : 1;
  unsigned bit7 : 1;
} REG8;

typedef struct
{
  unsigned bit0 : 1;
  unsigned bit1 : 1;
  unsigned bit2 : 1;
  unsigned bit3 : 1;
  unsigned bit4 : 1;
  unsigned bit5 : 1;
  unsigned bit6 : 1;
  unsigned bit7 : 1;
  unsigned bit8 : 1;
  unsigned bit9 : 1;
  unsigned bit10: 1;
  unsigned bit11: 1;
  unsigned bit12: 1;
  unsigned bit13: 1;
  unsigned bit14: 1;
  unsigned bit15: 1;
} REG16;



/**************************************************************************
STANDARD STRING TYPEDEFS
**************************************************************************/
typedef char    STRING_3[4];
typedef char    STRING_5[6];
typedef char    STRING_8[9];
typedef char    STRING_10[11];
typedef char    STRING_12[13];
typedef char    STRING_16[17];
typedef char    STRING_24[25];
typedef char    STRING_30[31];
typedef char    STRING_32[33];
typedef char    STRING_48[49];
typedef char    STRING_50[51];
typedef char    STRING_60[61];
typedef char    STRING_80[81];
typedef char    STRING_132[133];
typedef char	STRING_256[257];
typedef char	STRING_512[513];


/********************************************/
/* STANDARD SYSTEM SIZES					*/
/********************************************/
#define SIZE_UINT8  		(size_t)(sizeof (UINT8 ))
#define SIZE_SINT8  		(size_t)(sizeof (SINT8 ))

#define SIZE_UINT16  		(size_t)(sizeof (UINT16))
#define SIZE_SINT16 		(size_t)(sizeof (SINT16))

#define SIZE_UINT32  		(size_t)(sizeof (UINT_32))
#define SIZE_SINT32  		(size_t)(sizeof (SINT32))

#define SIZE_VOID  			(size_t)(sizeof (VOID  ))
#define SIZE_CHAR  			(size_t)(sizeof (CHAR  ))
#define SIZE_BOOL  			(size_t)(sizeof (BOOL  ))
#define SIZE_TIME_T			(size_t)(sizeof (TIME_T))

#define SIZE_SINGLE			(size_t)(sizeof (SINGLE))
#define SIZE_DOUBLE			(size_t)(sizeof (DOUBLE))

#define	SIZE_STRING_3   	(size_t)(sizeof (STRING_3  ))
#define	SIZE_STRING_5   	(size_t)(sizeof (STRING_5  ))
#define	SIZE_STRING_8   	(size_t)(sizeof (STRING_8  ))
#define	SIZE_STRING_10  	(size_t)(sizeof (STRING_10 ))
#define	SIZE_STRING_12  	(size_t)(sizeof (STRING_12 ))
#define	SIZE_STRING_16  	(size_t)(sizeof (STRING_16 ))
#define	SIZE_STRING_24  	(size_t)(sizeof (STRING_24 ))
#define	SIZE_STRING_30  	(size_t)(sizeof (STRING_30 ))
#define	SIZE_STRING_32  	(size_t)(sizeof (STRING_32 ))
#define	SIZE_STRING_48  	(size_t)(sizeof (STRING_48 ))
#define	SIZE_STRING_50  	(size_t)(sizeof (STRING_50 ))
#define	SIZE_STRING_60  	(size_t)(sizeof (STRING_60 ))
#define	SIZE_STRING_80  	(size_t)(sizeof (STRING_80 ))
#define	SIZE_STRING_132 	(size_t)(sizeof (STRING_132))
#define	SIZE_STRING_256 	(size_t)(sizeof (STRING_256))
#define	SIZE_STRING_512 	(size_t)(sizeof (STRING_512))


/**************************************************************************
STANDARD BIT MANIPULATIONS
**************************************************************************/
#define	SETBIT( target, bit )	((target) |= (1u << (bit)))
#define	CLRBIT( target, bit )	((target) &= ~(1u << (bit)))
#define	TOGBIT( target, bit )	((target) ^= (1u << (bit)))

#define	ISBITSET( target, bit )	(!!((target) & (1u << (bit))))
#define	ISBITCLR( target, bit )	( !((target) & (1u << (bit))))


/**************************************************************************/
#endif 


