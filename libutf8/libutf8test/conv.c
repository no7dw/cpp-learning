/*
 * conversion utility.  Used to convert filenames with non-utf8 characters
 * into valid filenames with utf8 characters
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int legal_utf8(char *src, int *clen) 
{
    unsigned long utf8_char = 0;

    if ((*src & 0x80) == 0) {
        utf8_char = *src;
        *clen = 1;
    }
        // is it a legal 2 byte char?
    else if (((src[0] & 0xe0) == 0xc0) && (src[1] != '\0') &&
             ((src[1] & 0xc0) == 0x80)) {
        utf8_char = (src[0] & 0x1f);
        utf8_char = (utf8_char << 6) | (src[1] & 0x3f);
        *clen = 2;
    }
        // check for legal 3 byte char
    else if (((src[0] & 0xf0) == 0xe0) && (src[1] != '\0') &&
             ((src[1] & 0xc0) == 0x80) && (src[2] != '\0') &&
             ((src[2] & 0xc0) == 0x80)) {
        utf8_char = (src[0] & 0x0f);
        utf8_char = (utf8_char << 6) | (src[1] & 0x3f);
        utf8_char = (utf8_char << 6) | (src[2] & 0x3f);
        *clen = 3;
    }
    
        // check for legal 4 byte char
    else if (((src[0] & 0xf8) == 0xf0) && (src[1] != '\0') &&
             ((src[1] & 0xc0) == 0x80) && (src[2] != '\0') &&
             ((src[2] & 0xc0) == 0x80) && (src[3] != '\0') &&
             ((src[3] & 0xc0) == 0x80)) {
        utf8_char = (src[0] & 0x07);
        utf8_char = (utf8_char << 6) | (src[1] & 0x3f);
        utf8_char = (utf8_char << 6) | (src[2] & 0x3f);
        utf8_char = (utf8_char << 6) | (src[3] & 0x3f);
        *clen = 4;
    }
    else {
            // illegal utf8 char
        return 0;
    }

        // now we obtain the utf8 char.  although the form is correct,
        // make sure the value is within legal utf8 range.
    if ((utf8_char < 0xD800 || utf8_char > 0xDFFF) &&
        (utf8_char <= 0x0010FFFF) && (utf8_char != 0xFFFE) &&
        (utf8_char != 0xFFFF))
        return 1;

    return 0;
}

/*
 * takes a '\0' terminated src string, and converted to destination.
 * We convert any illegal utf8 characters with '0xFFFD'.
 */
int utf8_convert(char * src, char* dest, int dest_len) 
{
    int clen;
    char utf8_re[3] = {0xef, 0xbf, 0xbd}; // 0xFFFD
    
    memset(dest, 0, dest_len);
    while (*src != '\0') {
        if (legal_utf8(src, &clen)) {
            if (dest_len > clen) {
                memcpy(dest, src, clen);
                src += clen;
                dest += clen;
                dest_len -= clen;
            }
            else {
                printf("supplied dest too short\n");
                return 0;
            }
        }
        else {
                // an illegal utf8 char
            if (dest_len > 3) {
                memcpy(dest, utf8_re, 3);
                dest += 3;
                dest_len -= 3;
                src ++;
            }
            else {
                printf("supplied dest too short\n");
                return 0;
            }
        }
    }        
    return 1;
}

int main(void)
{
        char src[]="04 鏁板瓧1鍒";
        char dest[255]={0};
        int dest_len =255;
     int iresult = utf8_convert(src,  dest,  dest_len);
     printf("src : %s\n", src);
     printf("dest: %s\n", dest);
     return iresult;
}

