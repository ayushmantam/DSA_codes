#include<iostream>
using namespace std;
#include<vector>
int SolveUsingRecursion(int n,int k){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }
    int ans=(SolveUsingRecursion(n-2,k)+SolveUsingRecursion(n-1,k))*(k-1);
    return ans; 
}   

int SolveUsingMem(int n,int k,vector<int>&dp){
    if(n==1){
        return k;
    }
    if(n==2){
        return (k+k*(k-1));
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=(SolveUsingMem(n-2,k,dp)+SolveUsingMem(n-1,k,dp))*(k-1);
    return dp[n]; 
}
int SolveTab(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=(k+k*(k-1));

    for(int i=3;i<=n; i++){
         dp[i]=(dp[i-2]+dp[i-1])*(k-1);
    }
   
    return dp[n];
}  

int SolveSpaceOpt(int n,int k){
    int prev2=k;
    int prev1=(k+k*(k-1));
    
    for(int i=3;i<=n; i++){
        int curr=(prev2+prev1)*(k-1);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int main(){
    int n=4;
    int k=3;
    // k==no of diff colors 
    // int ans=SolveUsingRecursion(n,k);
    // cout<<"ans: "<<ans<<endl;

    // vector<int>dp(n+1,-1);
    // int ans=SolveUsingMem(n,k,dp);
    // cout<<"ans: "<<ans<<endl;

    // int ans=SolveTab(n,k);
    // cout<<"ans: "<<ans<<endl;

    int ans=SolveSpaceOpt(n,k);
    cout<<"ans: "<<ans<<endl;
    

    return 0;
}

// HOMEWORK 
// COUNT DEARRANGMENTS