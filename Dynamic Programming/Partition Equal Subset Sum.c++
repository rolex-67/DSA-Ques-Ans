//R
class Solution {
  public:
    bool solve(vector<int>& arr,int n,int index,int target){
        if(target<0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        bool include=solve(arr,n,index+1,target-arr[index]);
        bool exclude=solve(arr,n,index+1,target);
        return include or exclude;
        
    }
    
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        int target=sum/2;
        return solve(arr,n,0,target);
    }
};
//R+M
class Solution {
  public:
    bool solve(vector<int>& arr,int n,int index,int target,vector<vector<int>> &dp){
        if(target<0){
            return 0;
        }
        if(index>=n){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include=solve(arr,n,index+1,target-arr[index],dp);
        bool exclude=solve(arr,n,index+1,target,dp);
        return dp[index][target]=include or exclude;
        
    }
    
    bool equalPartition(vector<int>& arr) {
        
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(arr,n,0,target,dp);
    }
};
//Tab
class Solution {
  public:
    bool solve(vector<int>& arr,int n,int index,int target){
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
            
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool include=0;
                if(j>=arr[i]){
                include=dp[i+1][j-arr[i]];
                }
                bool exclude=dp[i+1][j];
                dp[i][j]=include || exclude;
                
                
            }
        }   
            
        
        return dp[0][target];
        
        
        
    }
    
    bool equalPartition(vector<int>& arr) {
        
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        int target=sum/2;
        
        return solve(arr,n,0,target);
    }
};
//SO
class Solution {
  public:
    bool solve(vector<int>& arr,int n,int index,int target){
        vector<int> curr(target+1,0);
        vector<int> next(target+1,0);
        curr[0]=1;
        next[0]=1;
            
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool include=0;
                if(j>=arr[i]){
                include=next[j-arr[i]];
                }
                bool exclude=next[j];
                curr[j]=include || exclude;
                
                
            }
            next=curr;
        }   
        
            
        
        return curr[target];
        
        
        
    }
    
    bool equalPartition(vector<int>& arr) {
        
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        if(sum%2==1){
            return 0;
        }
        int target=sum/2;
        
        return solve(arr,n,0,target);
    }
};
