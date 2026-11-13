#include "./include/zero.h"
#include <stdio.h>

#ifdef  DEBUG_MODE
#include <time.h>
#endif

int main(int argc, char const *argv[])
{
    #ifdef DEBUG_MODE
    struct timespec time_end;
    struct timespec time_start;
    timespec_get(&time_start,TIME_UTC);
    #endif
    zr_zero_count_t *zero_count;
    zr_malloc_zero_count(&zero_count);
    unsigned char *data = malloc(ZERO_SIZE_BUFFER);
    FILE *fp = fopen(argv[1],"rb");
    size_t size = 0;
    while (1)
    {
        size = fread(data,1,ZERO_SIZE_BUFFER,fp);
        if (zr_encoding_zero_count(zero_count->__zero,data,size)) {
            return 1;
        }
        if (size != ZERO_SIZE_BUFFER)
        {
            break;
        }
    }
    #ifdef DEBUG_MODE
    timespec_get(&time_end,TIME_UTC);
    printf("%ld.%ld\n",time_end.tv_sec - time_start.tv_sec,time_end.tv_nsec - time_start.tv_nsec);
    zr_printf_zero(zero_count->__zero);
    #endif
    free(data);
    zr_free_zero_count(zero_count);
    return 0;
}

