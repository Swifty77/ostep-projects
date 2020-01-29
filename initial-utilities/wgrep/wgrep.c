#define _GNU_SOURCE
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    
char line [100];
FILE *fp;
    
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]");
        exit(1);
    }
    
    ssize_t r;
    size_t t = 0;
    
    for (int i = 2; i < argc; i++){
        fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("wgrep: cannot open file");
            exit(1);
        }
        
        while ((r = getLine(&line, &t, fp)) != -1){
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
            }
        }
        fclose(fp);
    }
  
    return 0;
}
