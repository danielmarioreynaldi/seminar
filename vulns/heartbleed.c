#include <string.h>
#include <stdlib.h>

unsigned int payload = 10;
unsigned int padding = 16; 

int main(){
    unsigned char *buffer, *bp;
    unsigned char *pl;

    unsigned char P[] = "ABC";

    buffer = malloc(1 + 2 + payload + padding);
    if (buffer == NULL) return 1;
    bp = buffer;

    memcpy(bp, P, payload);
}
