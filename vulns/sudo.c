#include <stdlib.h>

int main(){
    char *user_args[] = {"test\\", NULL};  // user-supplied arguments
    char *cmdline = malloc(6);
    if (cmdline == NULL) return 1;
    char *dst = cmdline;

    for (int i = 0; user_args[i] != NULL; i++) {
        char *src = user_args[i];
        while (*src) {
            if (*src == '\\') {
                *dst++ = '\\';  
            }
            *dst++ = *src++;
        }
        *dst++ = ' ';
    }
    *dst = '\0';
}
