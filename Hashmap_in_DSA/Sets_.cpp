#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    s.insert(20); //size still 4 duplicay ignore
    for (auto it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<endl;
    }

//output
// 20
// 15
// 5
// 10

    cout<<"number of element: "<<s.size()<<endl; 

    //for clear whole set
    // s.clear();


    int key=25;

    if(s.find(key)==s.end()){
        cout<<"key NOT found"<<endl;
    }

    else{
        cout<<"key found\n";
    }

    int todeleteKey=5; 
    // s.erase(todeleteKey);
    // cout<<"number of element: "<<s.size()<<endl; 


    //erase by it
    auto it=s.find(todeleteKey);
    s.erase(it);
    cout<<"number of element: "<<s.size()<<endl; 

}