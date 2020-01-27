
#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp = fopen("mainn.c", "r");
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
    return 0;
}
