//#define _GNU_SOURCE
//#define _XOPEN_SOURCE 600
//#define  _POSIX_C_SOURCE 200809L
//#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    
char line [1000];
FILE *fp;
    
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]");
        exit(1);
    }
    
    ssize_t r;
    size_t n = 0;
    
    for (int i = 2; i < argc; i++){
        fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("wgrep: cannot open file");
            exit(1);
        }
        
        while ((r = getLine(&line, &n, fp)) != -1){
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
            }
        }
        fclose(fp);
    }
  
    return 0;
}
