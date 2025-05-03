#include <stdint.h>
#include <stdlib.h>
#define LOOKASIDE_SMALL 128

int sz = 1200;
int nBig;
int nSm;
int cnt = 2500000;


// triggered when user calls sqlite3_db_config(db, SQLITE_DBCONFIG_LOOKASIDE, NULL , sz , cnt, NULL);
int main(){
    int64_t szAlloc = sz*(int64_t)cnt;

    if( sz >= LOOKASIDE_SMALL*3 ){
        nBig = szAlloc/(3*LOOKASIDE_SMALL+sz);
        nSm = (szAlloc - sz*nBig)/LOOKASIDE_SMALL;
    }

    // Some code logic
    char *buff = malloc(nSm);
    if (buff == NULL) return 1;
    return 0;
}
