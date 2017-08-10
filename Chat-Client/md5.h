#ifndef MD5_H
#define MD5_H

#include <string.h>

typedef unsigned long int UINT4;

/* Data structure for MD5 (Message Digest) computation */
typedef struct {
    UINT4 i[2];                   /* number of _bits_ handled mod 2^64 */
    UINT4 buf[4];                                    /* scratch buffer */
    unsigned char in[64];                              /* input buffer */
    unsigned char digest[16];     /* actual digest after MD5Final call */
} MD5_CTX;

void MD5Init (MD5_CTX *);
void MD5Update (MD5_CTX *, unsigned char *, unsigned int);
void MD5Final (MD5_CTX *);
char *MDString (char *inString);
char *MDPrint (MD5_CTX *,char *);
void Transform (UINT4 *buf, UINT4 *in);
#endif // MD5_H
