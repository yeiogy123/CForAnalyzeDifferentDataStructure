#include <string.h>
#include <stdbool.h>
#include "search.h"
int main(int argc, char *argv[]) {
    int numberOfData, numberOfSearch;
    bool bst = false, bs = false, arr = false, ll = false, hash = false;
    for(int i = 1 ; i < argc ; i++){
        if(strcmp(argv[i],"-d") == 0){
            i++;
            numberOfData = atof(argv[i]);
        }else if(strcmp(argv[i],"-q")==0){
            i++;
            numberOfSearch = atof(argv[i]);
        }else if(strcmp(argv[i],"-bst")==0){
            bst = true;
        }else if(strcmp(argv[i],"-bs")==0){
            bs = true;
        }else if(strcmp(argv[i],"-arr")==0){
            arr = true;
        }else if(strcmp(argv[i],"-ll")==0){
            ll = true;
        }else if(strcmp(argv[i],"-hash")==0){
            hash = true;
        }
    }
    if(bst){
        buildBST(numberOfData,numberOfSearch);
    }
    if(bs){
        buildBs(numberOfData,numberOfSearch);
    }
    if(arr){
        buildArr(numberOfData,numberOfSearch);
    }
    if(ll){
        buildLl(numberOfData,numberOfSearch);
    }
    if(hash){
        buildHash(numberOfData,numberOfSearch);
    }
    return 0;
}
