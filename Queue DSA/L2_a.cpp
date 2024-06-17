#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverse(queue<int> &q){
    stack <int> s;

    //step1: put all elements of q into s
    while (!q.empty())
    {
        int element=q.front();
        q.pop();

        s.push(element);
    }

    //step2; put all element from stack in q
    while (!s.empty())
    {
        int element=s.top();
        s.pop();

        q.push(element);

    }    
}

void reverseByrec(queue<int>&q){
        if(q.empty()){
            return ;
        }

        //step1
        int temp=q.front();
        q.pop();

        //step2
        reverseByrec(q);

        //step3
        q.push(temp);
}

void reverseK(queue<int>&q,int k){
    //step1: queue-> k elements ->stacks
    stack<int>s;

    int count=0;
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        count++;
        if (count==k)
        {
            break;
        }   
    }
    
    while(!s.empty()){
        int temp=s.top();
        s.pop();

        q.push(temp);
    }

    //step C: push n-k element front to back
    count=0;
    int n=q.size();
    while (!q.empty())
    {
        int temp=q.front();
        q.pop();
        q.push(temp);
        count++;

        if (count==n-k)
        {
            break;
        }
        
    }
    
}

void interleaveQueue(queue<int>&q){
    //step1:seperate in two queue
     int n=q.size();
     if (q.empty())
     {
        return;
     }
     
     int k=n/2;
     int count=0;
     queue<int>q2;
     while (!q.empty())
     {
        int temp=q.front();
        q.pop();
        q2.push(temp);
        count++;

        if (count==k)
        {
            break;
        }
        
     } 

     //step2: interleaving start krdo
      while (!q.empty()&& !q2.empty())
      {
          int first=q2.front();
          q.push(first);

          int second=q.front();
          q.pop();
          q.push(second);
      }
      
     if (n&1)
     {
        int element=q.front();
        q.pop();
        q.push(element);

     }
     
}


int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // reverse(q);
    // reverseByrec(q);
    reverseK(q,3); 

    cout<<"printing Queue\n";
    while (!q.empty())   
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
}