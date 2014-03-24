#ifndef __SMB_2_H
#define __SMB_2_H

#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BOOL int
#define Undefined (-1)
#define False (0)
#define True (1)



#ifndef uint8
#define uint8 unsigned char
#endif

#if !defined(int16) && !defined(HAVE_INT16_FROM_RPC_RPC_H)
#  if (SIZEOF_SHORT == 4)
#    define int16 __ERROR___CANNOT_DETERMINE_TYPE_FOR_INT16;
#  else /* SIZEOF_SHORT != 4 */
#    define int16 short
#  endif /* SIZEOF_SHORT != 4 */
   /* needed to work around compile issue on HP-UX 11.x */
#  define _INT16	1
#endif

/*
 * Note we duplicate the size tests in the unsigned 
 * case as int16 may be a typedef from rpc/rpc.h
 */

#if !defined(uint16) && !defined(HAVE_UINT16_FROM_RPC_RPC_H)
#if (SIZEOF_SHORT == 4)
#define uint16 __ERROR___CANNOT_DETERMINE_TYPE_FOR_INT16;
#else /* SIZEOF_SHORT != 4 */
#define uint16 unsigned short
#endif /* SIZEOF_SHORT != 4 */
#endif

#if !defined(int32) && !defined(HAVE_INT32_FROM_RPC_RPC_H)
#  if (SIZEOF_INT == 4)
#    define int32 int
#  elif (SIZEOF_LONG == 4)
#    define int32 long
#  elif (SIZEOF_SHORT == 4)
#    define int32 short
#  else
     /* uggh - no 32 bit type?? probably a CRAY. just hope this works ... */
#    define int32 int
#  endif
   /* needed to work around compile issue on HP-UX 11.x */
#  define _INT32	1
#endif

/*
 * Note we duplicate the size tests in the unsigned 
 * case as int32 may be a typedef from rpc/rpc.h
 */

#if !defined(uint32) && !defined(HAVE_UINT32_FROM_RPC_RPC_H)
#if (SIZEOF_INT == 4)
#define uint32 unsigned int
#elif (SIZEOF_LONG == 4)
#define uint32 unsigned long
#elif (SIZEOF_SHORT == 4)
#define uint32 unsigned short
#else
/* uggh - no 32 bit type?? probably a CRAY. just hope this works ... */
#define uint32 unsigned
#endif
#endif

/*
 * check for 8 byte long long
 */

#if !defined(uint64)
#if (SIZEOF_LONG == 8)
#define uint64 unsigned long
#elif (SIZEOF_LONG_LONG == 8)
#define uint64 unsigned long long
#endif	/* don't lie.  If we don't have it, then don't use it */
#endif

#if !defined(int64)
#if (SIZEOF_LONG == 8)
#define int64 long
#elif (SIZEOF_LONG_LONG == 8)
#define int64 long long
#endif	/* don't lie.  If we don't have it, then don't use it */
#endif

typedef uint32 NTSTATUS;

typedef struct _smb_iconv_t {
        size_t (*direct)(void *cd, const char **inbuf, size_t *inbytesleft,
                         char **outbuf, size_t *outbytesleft);
        size_t (*pull)(void *cd, const char **inbuf, size_t *inbytesleft,
                       char **outbuf, size_t *outbytesleft);
        size_t (*push)(void *cd, const char **inbuf, size_t *inbytesleft,
                       char **outbuf, size_t *outbytesleft);
        void *cd_direct, *cd_pull, *cd_push;
        char *from_name, *to_name;
} *smb_iconv_t;

struct charset_functions {
	const char *name;
	size_t (*pull)(void *, const char **inbuf, size_t *inbytesleft,
				   char **outbuf, size_t *outbytesleft);
	size_t (*push)(void *, const char **inbuf, size_t *inbytesleft,
				   char **outbuf, size_t *outbytesleft);
	struct charset_functions *prev, *next;
};
#endif
