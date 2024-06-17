#include<iostream>
#include<vector>
using namespace std;
int BottomUpSolve(int n){
        // Step1:create dp array
        vector<int>dp(n+1,-1);

        // step2: base case
        dp[0]=0;
        // if(n==0){
        //     return dp[0];
        // }
        dp[1]=1;

        //step 3: topDown Approach me n kaise travel krra hai
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
 }

int main(){
    cout<<BottomUpSolve(6)<<endl;
}