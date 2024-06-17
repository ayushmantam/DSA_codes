#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size) 
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // queue full

        // single element case->first element

        // circular

        // normal flow

        if (front == 0 && rear == size - 1)
        {
            cout << "Q is full ,cannot insert\n";
            return;
        }
        else if (front == -1)
        { // starting of element insertion
            front = rear = 0;
        }

        // ghoome ke insertion
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }

        arr[rear] = data;
    }

    void pushFront(int data)
    {
        if (front == 0 && rear == size - 1)
        {
            cout << "Q is full ,cannot insert\n";
            return;
        }

        else if (front == -1)
        { // starting of element insertion
            front = rear = 0;
        }

        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = data;
    }

    void popFront()
    { // same as simple pop()
        // empty check
        // single elment
        //  circular nature
        //  normal flow

        if (front == -1)
        {
            cout << "Q is empty" << endl;
        }
        else if (front == rear)
        {
            arr[front] == -1;
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // front ko right most se zero par le aao
        }

        else
        {
            front++;
        }
    }

    void popRear(){
        //empty
        if(front==-1&&rear==-1){
            cout<<"Q is empty\n";
        }

        //single
        else if(front==rear){
             front=-1;
             rear=-1;
        } 
        
        //circular
        else if(rear==0){
            rear=size-1;
        }

        else{
            front--;
        }
    }

     

};