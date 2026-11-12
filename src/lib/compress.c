
#include "core.h"


int zr_encoding_zero_count(zr_zero_t *__restrict__ __zero, const unsigned char *__restrict__ __src, size_t __size) {
    zr_zero_t *__restrict__ __zero_n = __zero;

    for (size_t i = 0; i < __size; i++)
    {
        for (size_t z = 0; z < 256; z++)
        {
            if (__zero_n->__data == __src[i])
            {
                __zero_n->__freq ++;
            } else {
                if (__zero_n->__next == NULL)
                {
                    return 1;
                }
                __zero_n = __zero_n->__next;
            }
        }
        __zero_n = __zero;
    }

    return 0;
}
