class Solution {
public:
    bool check(vector<int>& base,vector<int>& newbox){
        if(newbox[0]<=base[0] && newbox[1]<=base[1] && newbox[2]<=base[2]){
            return true;
        }
        return false;
    }
    int solve(vector<vector<int>>& cuboids,int n,int curr,int prev,vector<vector<int>>& dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0;
        if(prev==-1 || check(cuboids[curr],cuboids[prev])){
            include=cuboids[curr][2]+solve(cuboids,n,curr+1,curr,dp);
        }
        int exclude=0+solve(cuboids,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);        



    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &i:cuboids){
            sort(i.begin(),i.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(cuboids,n,0,-1,dp);
    }
};
