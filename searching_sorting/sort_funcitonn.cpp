#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr{1,3,4,2,5,6,7};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    //printing
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}