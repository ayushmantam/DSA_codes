#include<iostream>
#include<queue>
using namespace std;
int main(){
    //creation
    queue<int>q;

    //insertion
    q.push(5);//front
    q.push(15);
    q.push(25);
    q.push(55);//rear
 
        //front = where deletion occurs
        //rear  = where addition occurs
        

    //size
    cout<<"Size of queue is: "<<q.size()<<endl;
    q.pop();

    cout<<"size of queue is:"<<q.size()<<endl;

    cout<<"q.empty() = "<<q.empty()<<endl;

    cout<<"q.front() ="<<q.front()<<endl;  //5 nikalne ke baad 15 front ban gya
         
}