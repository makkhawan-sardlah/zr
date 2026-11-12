#include "./include/zero.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    zr_zero_count_t *zero_count;
    zr_malloc_zero_count(&zero_count);
    unsigned char *data = malloc(4096);
    FILE *fp = fopen(argv[1],"rb");
    while (1)
    {
        size_t size = fread(data,1,4096,fp);
        zr_encoding_zero_count(zero_count->__zero,data,size);
        if (size != 4096)
        {
            break;
        }
    }
    free(data);
    zr_printf_zero(zero_count->__zero);
    zr_free_zero_count(zero_count);
    return 0;
}

