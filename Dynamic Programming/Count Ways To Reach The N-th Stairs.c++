#include <bits/stdc++.h>
#define MOD 1000000007
int solve(int &nStairs){
    if(nStairs==0 || nStairs==1){
        return 1;
    }
    int curr=0;
    int prev2=1;
    int prev1=1;
    for(int i=2;i<=nStairs;i++){
        curr=(prev1 +prev2)%MOD;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}


int countDistinctWays(int nStairs) {
    return solve(nStairs);
    
}
//recusrion
// #include <bits/stdc++.h>
// #define MOD 1000000007
// int solve(int nStairs,int currstair,vector<int> &dp){
//     if(currstair==nStairs){
//         return 1;
//     }
//     if(currstair>nStairs){
//         return 0;
//     }

//     dp[nStairs]=(solve(nStairs,currstair+1,dp)+solve(nStairs,currstair+2,dp))%MOD;
//     return dp[nStairs];
// }


// int countDistinctWays(int nStairs) {
//     vector<int> dp(nStairs);
//     int ans=solve(nStairs,0,dp);
//     return ans;
// }
