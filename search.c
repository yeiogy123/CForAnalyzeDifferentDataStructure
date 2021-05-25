#include "search.h"
#define MAXHASH 1024
void gainData(int data[],int search[], int n, int m){
    int i;
    srand(1);
    for(i = 0 ; i <= n ; i++)
        data[i] = (rand() % (n * 10)) + 1;
    for(i = 0 ; i <= m ; i++)
        search[i] = (rand() % (m*10)) + 1;
}
void buildBST(int n, int m){
    int i, data[n], search[m];
    unsigned long different;
    nP bst = NULL;
    struct timeval begin, end;
    gainData(data,search,n,m);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= n ; i++)
        bst = insert(bst, data[i]);
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("bst:\nbuilding time:%ld microsecond\n",different);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= m ; i++){
        FindBstNode(bst,search[i]);
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("query time:%ld microsecond\n",different);
}
nP insert(nP root, int data){
    if(root == NULL){
        root = (nP)malloc(sizeof(node));
        root->data = data;
        root->left = root->right = NULL;
    }else if(data < root->data){
        root->left = insert(root->left,data);
    }else if(data > root->data){
        root->right = insert(root->right,data);
    }
    return root;
}
void FindBstNode(nP root, int i){
    while(root){
        if(root->data == i)
            break;
        else if(root->data < i && root->left)
            root = root->left;
        else if(root->data > i && root->right)
            root = root->right;
        else
            break;
    }
}
void buildBs(int n, int m){
    int data[n], search[m], i;
    unsigned long different;
    struct timeval begin, end;
    gettimeofday(&begin,NULL);
    gainData(data,search,n,m);
    qsort((void*)data,n,sizeof(data[0]),compare);
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("bs:\nbuilding time:%ld microsecond\n",different);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= m ; i++){
        binarySearch(data,search[i],m);
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("query time:%ld microsecond\n",different);
}
void binarySearch(const int data[],int target,int len){
    int front = 0, end = len, mid;
    while(front < end){
        mid = (front + end) / 2;
        if(data[mid] == target)
            break;
        else if(data[mid] > target)
            end = mid - 1;
        else if(data[mid] < target)
            front = mid + 1;
    }
}
int compare(const void* a,const void* b){
    return (*(int*)a)-(*(int*)b);
}
void buildArr(int n, int m){
    int data[n], search[m], i, j;
    unsigned long different;
    struct timeval begin, end;
    gettimeofday(&begin,NULL);
    gainData(data,search,n,m);
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("arr:\nbuilding time:%ld microsecond\n",different);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= m ; i++){
        for(j = 0 ; j <= n ; j++){
            if(search[i] == data[j])
                break;
        }
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("query time:%ld microsecond\n",different);
}
void buildLl(int n, int m){
    int data[n], search[m], i;
    unsigned long different;
    nP head = NULL;
    struct timeval begin, end;
    gainData(data,search,n,m);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= n ; i++){
        if(head == NULL){
            head = (nP)malloc(sizeof(node));
            head->right = head->left = NULL;
            head->data = data[i];
        }else{
            nP n = (nP)malloc(sizeof(node));
            n->data = data[i];
            n->right = head;
            n->left = NULL;
            head = n;
        }
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("ll:\nbuilding time:%ld microsecond\n",different);
    nP listPtr = head;
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= m ; i++){
        while(listPtr){
            if(listPtr->data == search[i])
                break;
            else
                listPtr = listPtr->right;
        }
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("query time:%ld microsecond\n",different);
}
void buildHash(int n, int m){
    int data[n], search[m], i, hv;
    unsigned long different;
    struct timeval begin, end;
    nP *HTable;
    HTable = (nP*)malloc(MAXHASH * sizeof(nP));
    gainData(data,search,n,m);
    gettimeofday(&begin,NULL);
    for(i = 0 ; i <= n ; i++){
        nP dptr;
        hv = data[i] % MAXHASH;
        dptr = HTable[hv];
        HTable[hv] = Hash_insert(dptr,data[i]);
    }gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("hash:\nbuilding time:%ld microsecond\n",different);
    gettimeofday(&begin,NULL);
    for(i = 0 ;  i <= m ; i++){
        hv = search[i] % MAXHASH;
        nP dqtr = HTable[hv];
        list_find(dqtr,search[i]);
    }
    gettimeofday(&end,NULL);
    different = 1000000*(end.tv_sec - begin.tv_sec)+end.tv_usec-begin.tv_usec;
    printf("query time:%ld microsecond\n",different);
}
nP Hash_insert(nP n, int data){
    nP newN = (nP)malloc(sizeof(node));
    newN->data = data;
    newN->right = n;
    return newN;
}
void list_find(nP n, int data){
    while(n){
        if(n->data == data)
            break;
        else
            n = n -> right;
    }
}