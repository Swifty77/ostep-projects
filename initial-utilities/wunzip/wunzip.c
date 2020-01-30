#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
    FILE *fp;
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]");
        exit(1);
    }
    
    int totalCars[1];
    char car[1];
    size_t byteSize = 4;
    size_t memb = 1;
    for (int i = 1; i < argc; i++){
        fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wunzip: cannot open file");
            exit(1);
        }
        
        while (fread(&totalCars, byteSize, memb, fp) == 1) {
            
            if (fread(car, memb, memb, fp) != 1) {
                break;
            }
                else {
                    for (int o = 0; o<totalCars[0]; o++) {
                        printf("%c", car[0]);
                    }
                }
            }
             fclose(fp);
        }
    return 0;
}

