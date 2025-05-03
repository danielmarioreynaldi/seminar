#include <stdlib.h>

int main(){
    size_t initial_size = 1024;
    char* data = malloc(initial_size);
    if (data == NULL) return 1;


    size_t new_size = 2048;
    data = realloc(data, new_size);
/*    if (data == NULL){
        // do something
    }
*/
    return 0;
}
