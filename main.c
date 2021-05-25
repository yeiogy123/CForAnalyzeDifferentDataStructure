#include <string.h>
#include "search.h"
int main(int argc, char *argv[]) {
    int numberOfData, numberOfSearch;
    for(int i = 1 ; i < argc ; i++){
        if(strcmp(argv[i],"-d") == 0){
            i++;
            numberOfData = atof(argv[i]);
        }else if(strcmp(argv[i],"-q")==0){
            i++;
            numberOfSearch = atof(argv[i]);
        }else if(strcmp(argv[i],"-bst")==0){
            buildBST(numberOfData,numberOfSearch);
        }else if(strcmp(argv[i],"-bs")==0){
            buildBs(numberOfData,numberOfSearch);
        }else if(strcmp(argv[i],"-arr")==0){
            buildArr(numberOfData,numberOfSearch);
        }else if(strcmp(argv[i],"-ll")==0){
            buildLl(numberOfData,numberOfSearch);
        }else if(strcmp(argv[i],"-hash")==0){
            buildHash(numberOfData,numberOfSearch);
        }
    }
    return 0;
}
