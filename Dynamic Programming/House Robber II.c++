#include <bits/stdc++.h> 
long long int solve(vector<int> &nums,int n){
    long long int prev2=0;
    long long int prev1=nums[0];
    for(int i=1;i<n;i++){
        long long int include=prev2+nums[i];
        long long int exclude=prev1+0;
        long long int maxi=max(include,exclude);
        prev2=prev1;
        prev1=maxi;

    }
    
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    vector<int> first,second;
    for(int i=0;i<n;i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
    }
     return max(solve(first, first.size()), solve(second, second.size()));
}



// #include <bits/stdc++.h> 
// long long int solve(vector<int>& valueInHouse,int n,vector<int> &dp){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return valueInHouse[0];
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     int include=solve(valueInHouse,n-2,dp)+valueInHouse[n];
//     int exclude=solve(valueInHouse,n-1,dp)+0;
//     dp[n]= max(include,exclude);

//     return dp[n];
// }

// long long int houseRobber(vector<int>& valueInHouse)
// {
//     int n=valueInHouse.size();
//     vector<int> dp(n,-1);
//     return solve(valueInHouse,n-1,dp);
// }

// #include <bits/stdc++.h> 
// long long int solve(vector<int>& valueInHouse,int n){
//     if(n<0){
//         return 0;
//     }
//     if(n==0){
//         return valueInHouse[0];
//     }
//     long long int include=solve(valueInHouse,n-2)+valueInHouse[n];
//     long long int exclude=solve(valueInHouse,n-1)+0;
//     return max(include,exclude);
// }

// long long int houseRobber(vector<int>& valueInHouse)
// {
//     int n=valueInHouse.size();
//     if(n==1){
//         return valueInHouse[0];
//     }
//     vector<int> first,second;
//     for(int i=0;i<n;i++){
//         if(i!=n-1){
//             first.push_back(valueInHouse[i]);
//         }
//         if(i!=0){
//             second.push_back(valueInHouse[i]);
//         }
//     }
//     return max(solve(first, first.size() - 1), solve(second, second.size() - 1));
// }
