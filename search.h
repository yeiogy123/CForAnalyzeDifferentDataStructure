//
// Created by User on 2021/5/25.
//

#ifndef PD_HW02_SEARCH_H
#define PD_HW02_SEARCH_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct node * nP;
typedef struct node{
    int data;
    nP left, right;
}node;
void buildBST(int, int);
nP insert(nP, int);
void FindBstNode(nP, int);
int compare(const void*, const void*);
void binarySearch(const int [],int,int);
void buildBs(int, int);
void buildArr(int, int);
void buildLl(int, int);
void buildHash(int, int);
nP Hash_insert(nP, int);
void list_find(nP, int);
#endif //PD_HW02_SEARCH_H
