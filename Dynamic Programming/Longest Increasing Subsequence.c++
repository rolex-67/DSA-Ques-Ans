//R
class Solution {
  public:
    int solve(vector<int>& arr,int n,int currindi,int previndi){
        if(currindi==n){
            return 0;
        }
        int include=0;
        if(previndi==-1 || arr[currindi]>arr[previndi]){
            include=1+solve(arr,n,currindi+1,currindi);
        }
        int exclude=0+solve(arr,n,currindi+1,previndi);
        return max(include,exclude);
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,n,0,-1);
        
    }
};
//R+M
class Solution {
  public:
    int solve(vector<int>& arr,int n,int currindi,int previndi,vector<vector<int>>& dp){
        if(currindi==n){
            return 0;
        }
        if(dp[currindi][previndi+1]!=-1){
            return dp[currindi][previndi+1];
        }
        int include=0;
        if(previndi==-1 || arr[currindi]>arr[previndi]){
            include=1+solve(arr,n,currindi+1,currindi,dp);
        }
        int exclude=0+solve(arr,n,currindi+1,previndi,dp);
        return dp[currindi][previndi+1]=max(include,exclude);
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(arr,n,0,-1,dp);
        
    }
};
//Tab
class Solution {
  public:
    int solve(vector<int>& arr,int n,int currindi,int previndi){
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int currindi=n-1;currindi>=0;currindi--){
            for(int previndi=currindi-1;previndi>=-1;previndi--){
                int include=0;
                if(previndi==-1 || arr[currindi]>arr[previndi]){
                    include=1+dp[currindi+1][currindi+1];
                    }
                int exclude=0+dp[currindi+1][previndi+1];
                dp[currindi][previndi+1]=max(include,exclude);
            }
        }
        return dp[0][0];
        
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,n,0,-1);
        
    }
};
//SO
class Solution {
  public:
    int solve(vector<int>& arr,int n,int currindi,int previndi){
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);
        
        for(int currindi=n-1;currindi>=0;currindi--){
            for(int previndi=currindi-1;previndi>=-1;previndi--){
                int include=0;
                if(previndi==-1 || arr[currindi]>arr[previndi]){
                    include=1+next[currindi+1];
                    }
                int exclude=0+next[previndi+1];
                curr[previndi+1]=max(include,exclude);
            }
            next=curr;
        }
        return next[0];
        
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,n,0,-1);
        
    }
};
//DP+BINARYS
class Solution {
  public:
    int solve(vector<int>& arr,int n){
        if(n==0){
            return 0;
        }
        vector<int> ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()){
                ans.push_back(arr[i]);
            }
            else{
                int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[index]=arr[i];
            }
        }
        return ans.size();
        
    }
    int lis(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,n);
        
    }
};
