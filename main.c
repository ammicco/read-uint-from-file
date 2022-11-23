#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "read_file.h"

static void Usage(){
    puts("Usage: ./main \"file to read\" \"bit to read\"\nexit.");
}

int main(int argc, char **argv){
    FILE *f; 
    uint64_t *b;
    size_t bit_num = atoi(argv[2]);

    if(argc < 3){
        Usage();
        return -1;
    }
    
    f = fopen(argv[1], "rb");

    if(!f){
        fputs("Open file error", stderr);
        return -1;
    }

    if(bit_num != 64 && bit_num != 32 && bit_num != 16 && bit_num != 8){
        fputs("argv[2] not allowed.\nexit\n", stderr);
        return -1;
    }

    b = (uint64_t *) readbit(f, bit_num);

    fclose(f);

    printf("Read %zu bit -> %lu\n", bit_num, *(b));

    return 0;
}