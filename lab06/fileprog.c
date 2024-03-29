#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000


int main(int argc, char **argv){
    FILE *infile;
    int my_array[ARRAY_SIZE];
    int num_items;
    int i;

    if(NULL == (infile = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    num_items = 0;
    while(num_items <ARRAY_SIZE && 1==fscanf(infile,"%d", &my_array[num_items])) {
        num_items++;
    }

    fclose(infile);

    for(i=0;i<num_items;i++){
        printf("%d\n", my_array[i]);
    }
    return EXIT_SUCCESS;
}

