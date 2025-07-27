//S.O.
#include<queue>
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    
    int ans=0;
    queue<pair<int,int>> weekly;
    queue<pair<int,int>> monthly;
    for(int day:days){
        while(!monthly.empty() && monthly.front().first+30<=day){
            monthly.pop();
        }
        while(!weekly.empty() && weekly.front().first+7<=day){
            weekly.pop();
        }
        weekly.push(make_pair(day,ans+cost[1]));
        monthly.push(make_pair(day,ans+cost[2]));
        ans=min(ans+cost[0],min(weekly.front().second,monthly.front().second));
    }
    return ans;
}

//R+M
// int solve(int n, vector<int>& days, vector<int>& cost, int k,vector<int> &dp) {
//     if (k >= n) {
//         return 0;
//     }
//     if(dp[k]!=-1){
//         return dp[k];
//     }

//     int option1 = cost[0] + solve(n, days, cost, k + 1,dp);


//     int i; 
//     for (i = k; i < n && days[i] < days[k] + 7; i++) {

//     }
//     int option2 = cost[1] + solve(n, days, cost, i,dp); 


//     for (i = k; i < n && days[i] < days[k] + 30; i++) {
        
//     }
//     int option3 = cost[2] + solve(n, days, cost, i,dp); 

//     dp[k]= min(option1,min(option2, option3));
//     return dp[k];
// }


// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
//     vector<int> dp(n+1,-1);
//     return solve(n,days,cost,0,dp);
// }

//tab
// int solve(int n, vector<int>& days, vector<int>& cost, int k) {
//     vector<int> dp(n+1,INT_MAX);
//     dp[n]=0;
//     for(int k=n-1;k>=0;k--){
//     int option1 = cost[0] + dp[k + 1];
//     int i; 
//     for (i = k; i < n && days[i] < days[k] + 7; i++);
//     int option2 = cost[1] +dp[i]; 


//     for (i = k; i < n && days[i] < days[k] + 30; i++);
//     int option3 = cost[2] +dp[i]; 
//     dp[k]= min(option1,min(option2, option3));
//     }
    
//     return dp[0];
// }


// int minimumCoins(int n, vector<int> days, vector<int> cost)
// {
    
//     return solve(n,days,cost,0);
// }
