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
    
    for (int i = 0; i < argc; i++){
        fp = fopen(argv[i], "r");
        
        if (fp == NULL) {
            printf("wgrep: cannot open file");
            exit(1);
        }
        
        while 
    }
    
    
    
//    = fopen(argv[], "r");
    

    
    
    
    
    return 0;
}
