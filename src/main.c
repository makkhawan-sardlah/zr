#include "./include/zero.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    zr_zero_count_t *zero_count;
    zr_malloc_zero_count(&zero_count);
    printf("%p\n",zero_count);
    zr_free_zero_count(zero_count);
    return 0;
}

