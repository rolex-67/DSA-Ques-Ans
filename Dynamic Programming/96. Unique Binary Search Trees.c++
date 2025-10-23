//Recursion
// class Solution {
// public:
//     int numTrees(int n) {
//         if(n==0 || n==1){
//             return 1;
//         }
//         int ans=0;
//         for(int i=1;i<=n;i++){

//             ans=ans+numTrees(i-1)*numTrees(n-i);
//         }
        
//         return ans;
//     }
// };
//Memo
// class Solution {
// public:
//     int solve(int n,vector<int>& dp){
//         if(n==0 || n==1){
//             return 1;
//         }
//         int ans=0;
//         if(dp[n]!=-0){
//             return dp[n];
//         }
//         for(int i=1;i<=n;i++){

//             ans=ans+solve(i-1,dp)*solve(n-i,dp);
            
//         }
//         dp[n]=ans;
//         return dp[n];
//     }
//     int numTrees(int n) {
//         vector<int> dp(n+1,0);
//         return solve(n,dp);
//     }
// };
