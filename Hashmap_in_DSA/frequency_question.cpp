#include<iostream>
using namespace std;
#include<unordered_map>
#include<map>
int main(){

    string str="thiruananthpuram";
    // unordered_map<char,int>freq;
    map<char,int>freq;

    for (int i = 0; i <  str.length(); i++)
    {
        freq[str[i]]++;
    }

    for(auto i:freq){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
}
//unorderded map used
// m -> 1
// p -> 1
// n -> 2
// a -> 3
// u -> 2
// h -> 2
// r -> 2
// t -> 2
// i -> 1


// ordered map used
// a -> 3
// h -> 2
// i -> 1
// m -> 1
// n -> 2
// p -> 1
// r -> 2
// t -> 2
// u -> 2