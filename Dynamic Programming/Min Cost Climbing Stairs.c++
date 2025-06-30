class Solution {
public:
    int solve(vector<int>& cost,int n,vector<int> &dp){
        //Base case
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        //step3:
        if(dp[n]!=-1){
            return dp[n];
        }
        //Step2:
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //Step1:Recurive+Memoization
        vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};
// class Solution {
// public:
//     int solve(vector<int>& cost,int n){
//         //Base case
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
//         return ans;
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();
//         int ans=min(solve(cost,n-1),solve(cost,n-2));
//         return ans;
//     }
// };
