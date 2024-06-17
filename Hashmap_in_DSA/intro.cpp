#include<iostream>
#include<map>
#include<unordered_map>
//MOST IMP question of dsa is design a data structure which ca perform se insertion,deletion ,serching and get ramdom O(1) me kar pao

//LINK
//https://www.geeksforgeeks.org/hashing-data-structure/

using namespace std;
int main(){

    //creation
    // unordered_map<int,int> m;
    // unordered_map<string,int> m;
    map<string,int> m;

    
    //insertion method 1 (using pairs)
    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);

    //Mthod 2
    pair<string,int>pair2("love",2);
    m.insert(pair2);

    //Method 3
    m["mera"]=1;  //1st time me creation

    //what will happen
    m["mera"]=2;   //2nd and so on time updation
    //har ek key ke corresponding ek hi value assign hogi

          //Search
     cout<<m["mera"]<<endl;  //output=2     
    
    cout<<m.at("babbar")<<endl;//output=3
    
    //cout<<m .at("unknown")<<endl; //output=error key not found r out of range
    cout<<m["unknown"]<<endl;  //output=0     
    cout<<m.at("unknown")<<endl;//now output =0  because iske pahli wali line ne 0 entry bana di "unknown" ke liye

    //size
    cout<<m.size()<<endl;//output=4

    //to check presence we use count function
    cout<<m.count("bro")<<endl; //output=0  bcoz not present
    cout<<m.count("babbar")<<endl; //output=1  bcoz present

    //erase
    m.erase("love");
    cout<<m.size()<<endl;//op=3  now size  is 3

    //Transversing
    //M1
    // for (auto i:m)
    // {
    //     cout<<i.first<<" "<<i.second<<endl;
    // i++;
    // }


    // using iterator M2
    // unordered_map<string,int> :: iterator it=m.begin();
    map<string,int> :: iterator it=m.begin();


    while (it !=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
//output for if we made unordered map
// unknown 0
// mera 2 
// babbar 3

//output if we made map 
// babbar 3
// mera 2
// unknown 0    
    
 
return  0;
}