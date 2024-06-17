#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
int maximumFrecuency(vector<int>&arr,int n){

    unordered_map<int,int>count;

    int maxFreq=0;
    int maxAns=0;

    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;//update hota rahega
        maxFreq=max(maxFreq,count[arr[i]]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (maxFreq==count[arr[i]])
        {
            maxAns=arr[i];
            break;
        }
        
    }
    

    return maxAns;
}