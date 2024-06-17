#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;
        rear=0;
    }

    void push(int data){
        if(rear==size){
            cout<<"q is full\n";
        }
        else
        {
            arr[rear]=data;
            rear++;
        }
        
    }

    void pop(){
        if(front==rear){
            cout<<"q is empty\n";
        }

        else
        {
            arr[front]=-1; //can be skip //mark kar rhe hai uss element ko
            front++;

            if (front==rear)//matlab queue empty hai front aur rear ko zero se hi shuru kar dete kyo hum beech me se kare
            {
                front=0;
                rear=0;
            }
            
        }
        
    }

    int getFront(){
        if(front==rear){
            cout<<"q is empty\n";
        }
        else
        {
            return arr[front];    
        }
    }

    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
    
    int getSize(){
          return rear-front;
    }
};

int main(){
        Queue q(18);

        q.push(5);
        q.push(15);
        q.push(25);
        q.push(55);

        cout<<"size of "<<q.getSize()<<endl;

        q.pop();
        cout<<"Size of queue  is :"<<q.getSize()<<endl;

        cout<<"Front element is :"<<q.getFront()<<endl;

        if (q.isEmpty())
        {
            cout<<"queue  is empty\n";
        }
        else
        {
            cout<<"queue is not empty\n";
        }

        
        
}
