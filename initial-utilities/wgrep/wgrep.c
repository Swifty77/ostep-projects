//#define _GNU_SOURCE
//#define _XOPEN_SOURCE 600
//#define  _POSIX_C_SOURCE 200809L
//#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    
char line [1000]; //stores positive line matches
FILE *fp;
    
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]");
        exit(1);
    }
    
    ssize_t r;    //size of blocks
    size_t n = 0; // line size
    
    for (int i = 2; i < argc; i++){
        fp = fopen(argv[i], "r"); //open file
        
        if (fp == NULL) {
            printf("wgrep: cannot open file");
            exit(1);
        }
        
        //read the line
        while ((r = getLine(&line, &n, fp)) != -1){
            // check if it contains search term
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line); //prints line with search term
            }
        }
        fclose(fp);
    }
  
    return 0;
}
