#include<iostream>
#include<vector>
using namespace std;

int indexOfPeak(vector<int>arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while (s<e)
    {
        if (arr[mid]<arr[mid+1])
        {
            //right search (int line A)
            s=mid+1;
        }

        else //(arr[mid]>arr[mid+1])
        {
            //(in line B or at the peak element)
            e=mid;
        }
        mid=s+(e-s)/2;
        
    }
    return e; //or s   //kyonki lasst me s==e ho jata hai
}
int main(){
    vector<int>arr{1,2,3,4,5,7,6,4};
    int ans=indexOfPeak(arr);
    cout<<"ans is "<<arr[ans]<<endl;
    
}