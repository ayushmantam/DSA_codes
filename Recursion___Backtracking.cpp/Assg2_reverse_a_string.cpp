#include<iostream>
using namespace std;
void reverse(string &str,int start,int end){
    if(start>=end){
        return;
    }
    
    swap(str[start],str[end]);
    
    return reverse(str,start+1,end-1);
}
int main(){
    string str="ayushman";
    int start=0;
    int end=str.length()-1;
    reverse(str,start,end);
    cout<<str;
    return 0;
}