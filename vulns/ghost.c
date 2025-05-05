
#include <stdio.h>
#include <string.h>

void vulnerable_function(const char *hostname) {
    char buff[1024];

    // VULNERABILITY: No bounds check
    strcpy(buff, hostname);  // Buffer overflow possible here
    printf("Processed: %s\n", buff);
}

int main() {
    char large_input[2048];
    memset(large_input, 'A', sizeof(large_input) - 1);
    large_input[2047] = '\0';

    vulnerable_function(large_input);
    return 0;
}
