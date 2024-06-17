#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string str="babbar";
    stack<char> s;
    //putting string in stack
    for (int  i = 0; i < str.length(); i++)
    {
        char ch=str[i];
        s.push(ch);
    }
    string ans="";  //initialising empty string
    
    while (!s.empty())
    {
        char ch=s.top();
        ans.push_back(ch);

        s.pop();
    }
    cout<<"answer is :"<<ans<<endl;
    return 0;

 //answer is: rabbab  
}