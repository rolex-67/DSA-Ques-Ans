class Solution {
public:
    int solve(int k, vector<int>& prices,int index,int buy,vector<vector<vector<int>>>& dp){
        int n=prices.size();
        if(index>=n){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[index][buy][k]!=-1){
            return dp[index][buy][k];
        }
        int profit=0;
        if(buy){
            profit=max( (-prices[index]+solve(k,prices,index+1,0,dp)),(0+solve(k,prices,index+1,1,dp)) );
        }
        else{
            profit=max( (prices[index]+solve(k-1,prices,index+1,1,dp)),(0+solve(k,prices,index+1,0,dp)) );
        }
        return dp[index][buy][k]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return solve(k,prices,0,1,dp);
    }
};
