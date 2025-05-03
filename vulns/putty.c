#include <stdio.h>

int main(){
    char sizestr[4];		
    int i;

    char *buf = "100 asdfasdfasdfasdfaasdfasdfasdfasdfasdfasdfasdf";
    long permissions;
        
    if (sscanf(buf, "%lo %s %n", &permissions, sizestr, &i) != 2) {
        //do something
    }
    
    return 0;
}
