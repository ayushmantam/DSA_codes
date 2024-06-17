#include<iostream>
#include<stack>
#include<string>
using namespace std;
void solve(stack<int>&inputStack,int count ,int size){
    if (count==size/2)
    {
        inputStack.pop();//is baar top wale ko side me nhi rakha sedhe nikal diya
        return;
    }    
    int num=inputStack.top();//top wale ko ek side rakha
    inputStack.pop();//top wale ko nikala
    //Recursive call
    solve(inputStack,count+1,size);

    inputStack.push(num); //ek side wale ko wapis dala

}
void deleteMiddle(stack<int>&inputStack,int size){
        int count =0;
        solve(inputStack,count,size);

}