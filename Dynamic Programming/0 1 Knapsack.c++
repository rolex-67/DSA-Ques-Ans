//Space OPtimazation with 1D
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {
    vector<int> curr(capacity+1,0);

    for (int w = weight[0]; w <= capacity; w++) {
        curr[w] = value[0]; 
    }

    for (int index = 1; index < n; index++) {
        for (int w = capacity; w>=0; w--) {
            int include = 0;
            if (weight[index] <= w) {
                include = value[index] +curr[w - weight[index]];
            }
            int exclude =curr[w];
            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return solve(weight, value, n, maxWeight); 
}


//REC
// #include <bits/stdc++.h>
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity){
//     if(index==0){
//         if(weight[0]<=capacity){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }
    
//     int include=0;
//     if(weight[index]<=capacity){
//         include=value[index]+solve(weight,value,index-1,capacity-weight[index]);
//     }
//     int exclude=0+solve(weight,value,index-1,capacity);

//     int ans=max(include,exclude);
//     return ans;
// }


// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     return solve(weight,value,n-1,maxWeight);
	
// }


//R+M
// #include <bits/stdc++.h>
// int solve(vector<int> &weight, vector<int> &value, int index, int capacity,vector<vector<int>> &dp){
//     if(index==0){
//         if(weight[0]<=capacity){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[index][capacity]!=-1){
//         return dp[index][capacity];
//     }
    
//     int include=0;
//     if(weight[index]<=capacity){
//         include=value[index]+solve(weight,value,index-1,capacity-weight[index],dp);
//     }
//     int exclude=0+solve(weight,value,index-1,capacity,dp);

//     dp[index][capacity]=max(include,exclude);
//     return dp[index][capacity];
// }


// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
//     vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
//     return solve(weight,value,n-1,maxWeight,dp);
	
// }


//tab
// #include <bits/stdc++.h>
// using namespace std;
 
// int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {
//     vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

//     for (int w = weight[0]; w <= capacity; w++) {
//         dp[0][w] = value[0]; 
//     }

//     for (int index = 1; index < n; index++) {
//         for (int w = 0; w <= capacity; w++) {
//             int include = 0;
//             if (weight[index] <= w) {
//                 include = value[index] + dp[index - 1][w - weight[index]];
//             }
//             int exclude = dp[index - 1][w];
//             dp[index][w] = max(include, exclude);
//         }
//     }

//     return dp[n - 1][capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//     return solve(weight, value, n, maxWeight); 
// }

//Space OPTI using 2d
// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int> &weight, vector<int> &value, int n, int capacity) {
//     vector<int> prev(capacity + 1, 0);
//     vector<int> curr(capacity + 1, 0);

//     // Base case
//     for (int w = weight[0]; w <= capacity; w++) {
//         prev[w] = value[0];
//     }

//     for (int index = 1; index < n; index++) {
//         for (int w = 0; w <= capacity; w++) {
//             int include = 0;
//             if (weight[index] <= w) {
//                 include = value[index] + prev[w - weight[index]];
//             }
//             int exclude = prev[w];
//             curr[w] = max(include, exclude);
//         }
//         prev = curr; // Copy current row for next iteration
//     }

//     return prev[capacity];
// }

// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
//     return solve(weight, value, n, maxWeight); 
// }
