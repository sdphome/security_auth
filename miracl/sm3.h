/* ============================================================================
 * Copyright (c) 2010-2015.  All rights reserved.
 * SM3 Hash Cipher Algorithm: Digest length is 256-bit
 * ============================================================================
 */

#ifndef __SM3_HEADER__
#define __SM3_HEADER__


unsigned char *sm3(const unsigned char *d, unsigned int n, unsigned char *md);
/*
d:  data
n:  byte length
md: 32 bytes digest
*/


#endif
