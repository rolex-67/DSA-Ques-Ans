//Memory Optimization
#include <bits/stdc++.h>
int solve(vector<int> &nums,int n){
    int prev2=0;
    int prev1=nums[0];
    for(int i=1;i<n;i++){
        int include=prev2+nums[i];
        int exclude=prev1+0;
        int maxi=max(include,exclude);
        prev2=prev1;
        prev1=maxi;

    }
    
    return prev1;
} 
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return solve(nums,n);
}

// Recusrion
// #include <bits/stdc++.h>
// int solve(vector<int> &nums,int n){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return nums[0];
//     }
//     int include=solve(nums,n-2)+nums[n];
//     int exclude=solve(nums,n-1)+0;
//     return max(include,exclude);
// } 
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n=nums.size();
//     int ans=solve(nums,n-1);
//     return ans;
// }


// Memoization+Recusrion
// #include <bits/stdc++.h> 
// int solve(vector<int> &nums,int n,vector<int> &dp){
//     if(n==0){
//         return nums[0];
//     }
//     if(n<0){
//         return 0;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int incl=solve(nums,n-2,dp)+nums[n];
//     int exlu=solve(nums,n-1,dp)+0;
//     dp[n]=max(incl,exlu);
//     return dp[n];
// }

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n=nums.size();
//     // int ans=solve(nums,n-1);
//     // return ans;
//     vector<int> dp(n,-1);
//     return solve(nums,n-1,dp);
// }

// #include <bits/stdc++.h>
// int solve(vector<int> &nums,int n,vector<int> &dp){
//     dp[0]=nums[0];
//     for(int i=1;i<n;i++){
//         int include=dp[i-2]+nums[i];
//         int exclude=dp[i-1]+0;
//         dp[i]=max(include,exclude);
//     }
    
//     return dp[n-1];
// } 
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n=nums.size();
//     vector<int> dp(n,0);
//     int ans=solve(nums,n-1,dp);
//     return ans;
// }
