//S.O.
class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right=curr[j + 1];
                int diagonal = next[j + 1];
                int down =next[j];

        
                if (mat[i][j] == 1) {
                    curr[j] = 1 + min({right, diagonal, down});
                    maxi = max(maxi,curr[j]);
                    
                } 
                else {
                    curr[j] = 0;
                    
                }
            }
            next=curr;
        }
        return next[0];
        
    }

    int maxSquare(vector<vector<int>>& mat) {
        
        int maxi = 0;
        solve(mat, 0, 0, maxi);
        return maxi;
    }
};
//Recur
// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
//         if (i >= mat.size() || j >= mat[0].size()) {
//             return 0;
//         }

//         int right = solve(mat, i, j + 1, maxi);
//         int diagonal = solve(mat, i + 1, j + 1, maxi);
//         int down = solve(mat, i + 1, j, maxi);

//         int ans = 0;
//         if (mat[i][j] == 1) {
//             ans = 1 + min({right, diagonal, down});
//             maxi = max(maxi, ans);
//         }

//         return ans;
//     }

//     int maxSquare(vector<vector<int>>& mat) {
//         int maxi = 0;
//         solve(mat, 0, 0, maxi);
//         return maxi;
//     }
// };
//R+Memo
// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j, int &maxi,vector<vector<int>> &dp) {
//         if (i >= mat.size() || j >= mat[0].size()) {
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }

//         int right = solve(mat, i, j + 1, maxi,dp);
//         int diagonal = solve(mat, i + 1, j + 1, maxi,dp);
//         int down = solve(mat, i + 1, j, maxi,dp);

        
//         if (mat[i][j] == 1) {
//             dp[i][j] = 1 + min({right, diagonal, down});
//             maxi = max(maxi, dp[i][j]);
//         } 
//         else {
//             dp[i][j] = 0;
//         }

//         return dp[i][j];
//     }

//     int maxSquare(vector<vector<int>>& mat) {
//         int n=mat.size();
//         int m=mat[0].size();
//         vector<vector<int>> dp(n,vector<int> (m,-1));
//         int maxi = 0;
//         solve(mat, 0, 0, maxi,dp);
//         return maxi;
//     }
// };
//TAB
// class Solution {
// public:
//     int solve(vector<vector<int>>& mat, int i, int j, int &maxi) {
//         int n=mat.size();
//         int m=mat[0].size();
//         vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
//                 int right =dp[i][j + 1];
//                 int diagonal = dp[i + 1][j + 1];
//                 int down = dp[i + 1][j];

        
//                 if (mat[i][j] == 1) {
//                     dp[i][j] = 1 + min({right, diagonal, down});
//                     maxi = max(maxi, dp[i][j]);
                    
//                 } 
//                 else {
//                     dp[i][j] = 0;
                    
//                 }
//             }
//         }
//         return dp[0][0];
        
//     }

//     int maxSquare(vector<vector<int>>& mat) {
        
//         int maxi = 0;
//         solve(mat, 0, 0, maxi);
//         return maxi;
//     }
// };
