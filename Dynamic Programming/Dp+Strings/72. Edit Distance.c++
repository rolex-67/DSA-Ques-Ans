class Solution {
public:
    int solve(string word1, string word2,int n,int m,int i,int j){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            return solve(word1,word2,n,m,i+1,j+1);
        }
        else{
            //insert
            int insertans=1+solve(word1,word2,n,m,i,j+1);

            //delete
            int deleteans=1+solve(word1,word2,n,m,i+1,j);
            //REPLACE
            int replaceans=1+solve(word1,word2,n,m,i+1,j+1);
            ans=min(insertans,(min(deleteans,replaceans)));
        }
        return ans;


    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,word1.size(),word2.size(),0,0);
    }
};


class Solution {
public:
    int solve(string word1, string word2,int n,int m,int i,int j,vector<vector<int>>& dp){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(word1[i]==word2[j]){
            return solve(word1,word2,n,m,i+1,j+1,dp);
        }
        else{
            //insert
            int insertans=1+solve(word1,word2,n,m,i,j+1,dp);

            //delete
            int deleteans=1+solve(word1,word2,n,m,i+1,j,dp);
            //REPLACE
            int replaceans=1+solve(word1,word2,n,m,i+1,j+1,dp);
            ans=min(insertans,(min(deleteans,replaceans)));
            dp[i][j]=ans;
        }
        return ans;


    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return solve(word1,word2,word1.size(),word2.size(),0,0,dp);
    }
};
