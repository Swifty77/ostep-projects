#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]");
        exit(1);
    }
    
    int totalCars;            // counts repeated characters
    char car, lastCar = '\0'; // current and last characters
    size_t byteSize = 4;      // # of bytes to be written by fwrite
    size_t memb = 1;          // # of times record is written
    for (int i = 1; i< argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wzip: cannot open file");
            exit(1);
        }
        
        if (lastCar == '\0'){
            lastCar = getc(fp);
        }
        while ((car = getc(fp)) != EOF){
           
            if (car == lastCar) {
                totalCars++;
            }
            else {
                fwrite(&totalCars, byteSize, memb, stdout); //print number
                fwrite(&lastCar, memb, memb, stdout);       //print character
                totalCars = 1;
            }
            lastCar = car;
        }
        //prints last set once it goes through all of the files
        if (i == argc-1) {
            fwrite(&totalCars, byteSize, memb, stdout);
            fwrite(&lastCar, memb, memb, stdout);
            totalCars = 1;
        }
        fclose(fp);
        
    }
    
    
    
    
    
    return 0;
}
