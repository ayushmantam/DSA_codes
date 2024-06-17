#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
struct CirQueue
{
    int *arr;
    int front;
    int size;
    int rear;
};

typedef struct CirQueue CirQueue;

CirQueue* createCq(CirQueue* cq,int size){
    CirQueue* cq=(CirQueue*)malloc(sizeof(CirQueue*));
    cq->size=size;
    cq->arr=(int*)malloc(size*sizeof(int));
    cq->front=-1;
    cq->rear=-1;
    return cq;
}

void push(CirQueue* cq, int data){
    if()
}
