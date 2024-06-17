//               STACK IMPELEMENTATION USING ARRAYS
#include<iostream>
using namespace std;
class Stack{
   //preparation 
    public:
    int *arr;
    int top;
    int size;


    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];//dynamically memory allocation for array
        top=-1; //initialising top with -1
    }

    void push(int element){
            if (size-top>1)
            {
                top++;
                arr[top]=element;
            }
            
            {
                cout<<"Stack overflow"<<endl;
            }
    }
    
    void pop(){
        if (top>=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack underflow\n";
        }
    }
    int peek(){
        if (top>=0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack is Empty "<<endl;
            return -1;
        }       
    }
    bool isEmpty(){
        if (top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }       
    }
};
int main(){
    Stack st(5);
    st.push(22);    
    st.push(43);    
    st.push(44);  
    cout<<"1 peek element is "<<st.peek()<<endl;

    st.pop();
    cout<<"2 peek element is "<<st.peek()<<endl;
    st.pop();
    cout<<"3 peek element is "<<st.peek()<<endl;
    st.pop();
    cout<<"4 peek element is "<<st.peek()<<endl;

    if (st.isEmpty()){
        cout<<"stack is Empty mere dost\n";

    }
    else {
        cout<<"Stack is Not Empty\n";
    }
      
}