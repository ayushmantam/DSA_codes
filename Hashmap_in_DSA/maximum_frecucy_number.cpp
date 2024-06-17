#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
int maximumFrecuency(vector<int>&arr,int n){

    unordered_map<int,int>count;
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;//update hota rahega
    }

    int maxi=INT_MIN;
    int ans=-1;
    
    for(auto i:count){
        if (i.second>maxi)
        {
            maxi=i.second;
            ans=i.first;
        }   
    }

    return ans;
}