
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    if (argc == 0)
        exit(0);
    
for (int fileNum = 1; fileNum < argc; fileNum++) {

FILE *fp = fopen(argv[fileNum], "r");
if (fp == NULL) {
    printf("wcat: cannot open file\n");
    exit(1);
}

int bufferLength = 255;
char buffer[bufferLength];

while(fgets(buffer, bufferLength, fp)) {
    printf("%s", buffer);
}
fclose(fp);
    }
    return 0;
}
