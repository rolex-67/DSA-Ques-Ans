//R
class Solution {
  public:
    int solve(int faces,int dices,int target){
        if(target<0){
            return 0;
        }
        if(dices==0 && target!=0){
            return 0;
        }
        if(dices!=0 && target==0){
            return 0;
        }
        if(dices==0 && target==0){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(faces,dices-1,target-i);
        }
        return ans;
    }
    int noOfWays(int m, int n, int x) {
        return solve(m,n,x);
        
    }
};
//R+M
class Solution {
  public:
    int solve(int faces,int dices,int target,vector<vector<int>>& dp){
        if(target<0){
            return 0;
        }
        if(dices==0 && target!=0){
            return 0;
        }
        if(dices!=0 && target==0){
            return 0;
        }
        if(dices==0 && target==0){
            return 1;
        }
        if(dp[dices][target]!=-1){
            return dp[dices][target];
        }
        int ans=0;
        for(int i=1;i<=faces;i++){
            ans=ans+solve(faces,dices-1,target-i,dp);
        }
        return dp[dices][target]=ans;
    }
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        return solve(m,n,x,dp);
        
    }
};
//Tab
class Solution {
  public:
    int solve(int faces,int dices,int target){
        vector<vector<int>> dp(dices+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=dices;i++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int k=1;k<=faces;k++){
                    if(j-k>=0){
                       ans=ans+dp[i-1][j-k]; 
                    }
                }
                dp[i][j]=ans;
            }
        }
        return dp[dices][target];
        
    }
    int noOfWays(int m, int n, int x) {
        
        return solve(m,n,x);
        
    }
};
//SO
class Solution {
  public:
    int solve(int faces,int dices,int target){
        vector<int> prev(target+1,0);
        vector<int> curr(target+1,0);
        prev[0]=1;
        for(int i=1;i<=dices;i++){
            for(int j=1;j<=target;j++){
                int ans=0;
                for(int k=1;k<=faces;k++){
                    if(j-k>=0){
                       ans=ans+prev[j-k]; 
                    }
                }
                curr[j]=ans;
            }
            prev=curr;
        }
        return prev[target];
        
    }
    int noOfWays(int m, int n, int x) {
        
        return solve(m,n,x);
        
    }
};
