
#include "core.h"

#include <stdio.h>

int zr_malloc(zr_init_t *__restrict__ __zr,size_t *__restrict__ __size) {
    
}

int zr_malloc_zero(zr_zero_t **__restrict__ __zero) {
    zr_zero_t *__restrict__ __zero_init = malloc(sizeof(zr_zero_t));;
    zr_zero_t *__restrict__ __zero_n = __zero_init;
    for (size_t i = 0; i < 256; i++)
    {
        __zero_n->__data = i;
        __zero_n->__freq = 0;
        __zero_n->__next = malloc(sizeof(zr_zero_t));
        __zero_n = __zero_n->__next;
    }
    __zero_n->__next = NULL;
    *__zero = __zero_init;
    return 0;
}

int zr_free_zero(zr_zero_t *__restrict__ __zero) {
    zr_zero_t *__restrict__ __zero_n = __zero;
    while (1)
    {
        if (__zero_n->__next == NULL)
        {
            free(__zero_n);
            break;
        }
        else if (__zero_n->__next->__next == NULL)
        {
            free(__zero_n->__next);
            __zero_n->__next = NULL;
            __zero_n = __zero;
        } else {
            __zero_n = __zero_n->__next;
        }
    }
    return 0;
}

int zr_malloc_zero_count(zr_zero_count_t **__restrict__ __zero_count) {
    *__zero_count = malloc(sizeof(zr_zero_count_t));
    zr_zero_count_t *__zero_count_n = *__zero_count;
    zr_malloc_zero(&__zero_count_n->__init);
    __zero_count_n->__zero = __zero_count_n->__init;
}

int zr_free_zero_count(zr_zero_count_t *__restrict__ __zero_count) {
    zr_free_zero(__zero_count->__init);
    free(__zero_count);
}
