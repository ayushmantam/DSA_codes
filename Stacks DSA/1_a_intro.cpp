#include<iostream>
#include<stack>
using namespace std;
int main(){

    
    // creation 
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();
    cout<<"printing top element "<< s.top()<<endl;
    if (s.empty())
    {
        cout<<" stack is empty\n";
    }
    else
    {
        cout<<"stack is not empty\n";
    }

    cout<<"size of stack "<<s.size()<<endl;
    
   
    
}