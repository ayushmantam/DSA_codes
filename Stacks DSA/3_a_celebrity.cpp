
//everyone now celebrity
//celebrity konws noone

//given nXn maatrix
//matrix represent i , j ko jaannta hai ?

//Algo 1 brute force method

//algo 2 using stacks
#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution{
    public:
    //Function to find if there is a celebrity n the party or not
    //a b ko jaanta hai
    bool knows(vector<vector<int>> &M,int a,int b,int n){
        if (M[a][b]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
    public:
    int celebrity(vector<vector<int>> &M,int n){
    stack<int>s;
    //step1: push all element in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    //step2:
    while (s.size()>1)
    {
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if (knows(M,a,b,n))//a b ko janta hai
        {
            s.push(b);//bo ko ander daal do
        }
        else
        {
            s.push(a);
        }
    }
    int ans=s.top();
    //step3:single element in stack is potential celeb
    //so verify it
//abhi bhi pakka nhi hai ki wo celebrity ho
    bool rowCheck=false;
    int zeroCount=0;

    for (int i = 0; i < n; i++)
    {
        if (M[ans][i]==0)
        {
            zeroCount++;
        }
    }
    
    //all zeros
    if (zeroCount==n)
    {
        rowCheck=true;
    }


    //column check
    bool colCheck=false;
    int oneCount=0;

    for (int i = 0; i < n; i++)
    {
        if (M[i][ans]==1)
        {
            oneCount++;
        }
    }
       
      if (oneCount==n-1)//EXCEPT diagonal element
       {
        colCheck=true;
       }
       if (rowCheck==true&& colCheck==true)
       {
        return ans;
       }
       else
       {
        return -1;
       }  
    }
};

//TC =O(N)

//SEE SAME BUT CONSIZED CODE IN BABBAR NOTES


//THIS PROBLEM HAS MANY SOLUTION SO EXPLORE THEM