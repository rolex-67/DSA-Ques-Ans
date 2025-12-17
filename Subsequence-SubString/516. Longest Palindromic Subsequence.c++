//Recusrion
class Solution {
public:
    int solve(string s,string newstr,int i ,int j){
        int n=s.size();
        int m=newstr.size();
        if(i==n){
            return 0;
        }
        if(j==m){
            return 0;
        }
        if(s[i]==newstr[j]){
            return 1+solve(s,newstr,i+1,j+1);
        }
        else{
            return max(solve(s,newstr,i+1,j)  , (solve(s,newstr,i,j+1)));
        }
        
    }
    int longestPalindromeSubseq(string s) {
        string newstr=s;
        reverse(newstr.begin(),newstr.end());
        return solve(s,newstr,0,0);
    }
};

//Memo
class Solution {
public:
    int solve(string s,string newstr,int i ,int j,vector<vector<int>>& dp){
        int n=s.size();
        int m=newstr.size();
        if(i==n){
            return 0;
        }
        if(j==m){
            return 0;
        }
        int ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    
        if(s[i]==newstr[j]){
            ans= 1+solve(s,newstr,i+1,j+1,dp);
        }
        else{
            ans= max(solve(s,newstr,i+1,j,dp)  , (solve(s,newstr,i,j+1,dp)));
        }
        return dp[i][j]=ans;
        
    }
    int longestPalindromeSubseq(string s) {
        string newstr=s;
        reverse(newstr.begin(),newstr.end());
        int n=s.size();
        int m=newstr.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(s,newstr,0,0,dp);
    }
};

//Tab
class Solution {
public:
    int solve(string s, string newstr) {
        int n = s.size();
        int m = newstr.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == newstr[j]) {
                    ans = 1 +dp[i+1][j+1];
                } else {
                    ans = max( dp[i+1][j],dp[i][j+1] );
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }
    int longestPalindromeSubseq(string s) {
        string newstr = s;
        reverse(newstr.begin(), newstr.end());
        return solve(s, newstr);
    }
};
