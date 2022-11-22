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

    if(argc < 3){
        Usage();
        return -1;
    }
    
    f = fopen(argv[1], "rb");

    if(atoi(argv[2]) != 64 && atoi(argv[2]) != 32 && atoi(argv[2]) != 16 && atoi(argv[2]) != 8){
        fputs("argv[2] not allowed.\eexit\n", stderr);
        return -1;
    }

    b = (uint64_t *) readbit(f, atoi(argv[2]));

    fclose(f);

    printf("Read %d bit -> %lu\n", atoi(argv[2]), *(b));

    return 0;
}