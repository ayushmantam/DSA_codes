#include<iostream>
using namespace std;

class CirQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;


    CirQueue(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }


    void push(int data){
        //queue full

        //single element case->first element

        //circular

        //normal flow

        if (front== 0 &&  rear==size-1 )
        {
            cout<<"Q is full ,cannot insert\n";
        }
        else if(front==-1){//starting of element insertion
            front=rear=0;
            arr[rear]==data;
        }

        //ghoome ke insertion
        else if(rear==size-1&&front!=0){
            rear=0;
            arr[rear]=data;
        }

        else{
            rear++;
            arr[rear]=data;
        }
        
    }


    void pop(){
        //empty check
        //single elment
        // circular nature
        // normal flow

        if (front==-1){
            cout<<"Q is empty"<<endl;
        }
        else if(front==rear){
            arr[front]==-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;   //front ko right most se zero par le aao
        }

        else{
            front++;
        }
    }
     

};