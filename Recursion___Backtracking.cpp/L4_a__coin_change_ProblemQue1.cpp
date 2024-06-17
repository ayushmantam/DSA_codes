//HOMEWORK JISKE SOLUTION NAHI MILENGE
//1 letter tile combination
//2 sum of all subset XOR
//3 No of sqaure full arrays
//4  word break -1

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solve(vector<int>& arr,int target){
    //base case
    if (target==0)
    {
        return 0;
    }
    if (target<0)
    {   
        return INT_MAX;
    }

    int mini=INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans=solve(arr,target-arr[i]);
        if(ans!=INT_MAX)
        mini=min(mini,ans+1);
    }
    return mini;
    
}
int main(){
    vector<int>arr{1,2,3};
    int target=5;
 
    int ans=solve(arr,target);
    cout<<"Answer is :"<<ans<<endl;
}

// VIDEO KA 1.04 PART DEKH LO  


// TWO PATTERN WE HAVE LEARNT TILL NOW 

// 1 INCLUSION-EXCLUSION 
// 2 ELMENT FOR LOOP CALL 

