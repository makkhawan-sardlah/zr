
#define ZERO_KEY "ZR"

#define ZERO_VERSION 1

#include <stdlib.h>

typedef struct
{
    char *__header;
    int16_t __version;

    unsigned char __src;
    unsigned char __dst;
}zr_init_t;

typedef struct zr_zero_t
{
    unsigned char __data;
    long unsigned int __freq;
    struct zr_zero_t *__next;
}zr_zero_t;

typedef struct
{
    zr_zero_t *__zero;
    zr_zero_t *__init;
}zr_zero_count_t;

int zr_malloc_zero(zr_zero_t **__restrict__ __zero);
int zr_free_zero(zr_zero_t *__restrict__ __zero);
int zr_malloc_zero_count(zr_zero_count_t **__restrict__ __zero_count);
int zr_free_zero_count(zr_zero_count_t *__restrict__ __zero_count);
int zr_encoding_zero_count(zr_zero_t *__restrict__ __zero, const unsigned char *__restrict__ __src, size_t __size);
int zr_printf_zero(zr_zero_t *__restrict__ __zero);
