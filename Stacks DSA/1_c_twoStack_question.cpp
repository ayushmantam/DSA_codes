//implementation of two stacks in a array
#include<iostream>
using namespace std;
class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;
public:
    //Initialize Twostack
    TwoStack(int s){
        this->size=s;
        top1=-1;
        top2=s;  //array mr to 0 se size-1 tak hote hai
        arr=new int[s];//memory allocation in array
    }  
    void push1(int num){
        //atleast one space available
        if (top2-top1>1)
        {
            top1++;
            arr[top1]=num;
        }
        else
        {
            cout<<"Stack Overflow\n";
        }
    }
    void push2(int num){
        if (top2-top1>1)
        {
            top2--;
            arr[top2]=num;
        }
        else
        {
            cout<<"Stack Overflow\n";
        }
    }
    
    int pop1(){
        if (top1>=0)//atleast one ele should be present
        {
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    int pop2(){
        if (top2<size)//atleast one ele should be present
        {
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else
        {
            return -1;
        }
    }
    
};