class Solution {
public:
    int solve(vector<int>& prices,int index,int buy,int limit,vector<vector<vector<int>>>& dp){
        int n=prices.size();
        if(limit==0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(dp[index][buy][limit]!=-1){
            return dp[index][buy][limit];
        }
        int profit=0;
        if(buy){
            profit=max( (-prices[index]+solve(prices,index+1,0,limit,dp)), (0+solve(prices,index+1,1,limit,dp)) );
        }
        else{
            profit=max(prices[index]+solve(prices,index+1,1,limit-1,dp), (0+solve(prices,index+1,0,limit,dp)));
        }
        return dp[index][buy][limit]=profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int limit=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (limit+1,-1)));
        return solve(prices,0,1,2,dp);
    }
};
