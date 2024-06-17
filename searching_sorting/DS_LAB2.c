// Online C++ compiler to run C++ program online
#include<stdio.h>

struct Node{
    int data;
    struct Node* Link;
};

int main() {
    struct Node *start=NULL;
    struct Node s1,s2,s3;
    s1.data=10;
    s2.data=20;
    s3.data=30;
    start=&s1;
    s1.Link=&s2;
    s2.Link=&s3;
    s3.Link=NULL;
    struct Node *ptr=start;

    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->Link;
    }
    
    return 0;
}