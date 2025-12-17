//Recusrion
class Solution {
public:
    int solve(string text1, string text2,int n1,int n2,int i,int j){
        if(i==n1 ){
            return 0 ;
        }
        if(j==n2){
            return 0 ;
        }
        if(text1[i]==text2[j]){
            return 1+solve(text1,text2,n1,n2,i+1,j+1);
        }
        else{
            return max( (solve(text1,text2,n1,n2,i+1,j)),(solve(text1,text2,n1,n2,i,j+1)));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        return solve(text1,text2,n1,n2,0,0);
    }
};

//Memo
class Solution {
public:
    int solve(string text1, string text2,int n1,int n2,int i,int j,vector<vector<int>>& dp){
        if(i==n1 ){
            return 0 ;
        }
        if(j==n2){
            return 0 ;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(text1[i]==text2[j]){
            ans=1+solve(text1,text2,n1,n2,i+1,j+1,dp);
        }
        else{
            ans= max( (solve(text1,text2,n1,n2,i+1,j,dp)),(solve(text1,text2,n1,n2,i,j+1,dp)));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int> (n2,-1));
        return solve(text1,text2,n1,n2,0,0,dp);
    }
};

//Tab
class Solution {
public:
    int solve(string text1, string text2) {
        
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int ans = 0;
        for (int i = n1-1; i >= 0; i--) {
            for (int j = n2-1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    ans = 1 + dp[i+1][j+1];
                } else {
                    ans = max(dp[i+1][j],
                              dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2);
    }
};
