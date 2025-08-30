//R
class Solution {
public:
    int solve(int index,int endindex,vector<int>& slices,int sizi){
        if(sizi==0 || index>endindex){
            return 0;
        }
        int include=slices[index]+solve(index+2,endindex,slices,sizi-1);
        int exclude=0+solve(index+1,endindex,slices,sizi);
        return max(include,exclude);

    }
    int maxSizeSlices(vector<int>& slices) {
        int sizi=slices.size();
        int case1=solve(0,sizi-2,slices,sizi/3);
        int case2=solve(1,sizi-1,slices,sizi/3);
        return max(case1,case2);
    }
};
//R+m
class Solution {
public:
    int solve(int index,int endindex,vector<int>& slices,int sizi,vector<vector<int>>& dp){
        if(sizi==0 || index>endindex){
            return 0;
        }
        if(dp[index][sizi]!=-1){
            return dp[index][sizi];
        }
        int include=slices[index]+solve(index+2,endindex,slices,sizi-1,dp);
        int exclude=0+solve(index+1,endindex,slices,sizi,dp);
        return dp[index][sizi]=max(include,exclude);

    }
    int maxSizeSlices(vector<int>& slices) {
        int sizi=slices.size();
        vector<vector<int>> dp1(sizi,vector<int>(sizi/3+1,-1));
        vector<vector<int>> dp2(sizi,vector<int>(sizi/3+1,-1));
        int case1=solve(0,sizi-2,slices,sizi/3,dp1);
        int case2=solve(1,sizi-1,slices,sizi/3,dp2);
        return max(case1,case2);
    }
};
//Tab
class Solution {
public:
    int solve(vector<int>& slices){
        int sizi=slices.size();
        int k = sizi/3; // we must pick exactly n/3 slices

        vector<vector<int>> dp1(sizi+2,vector<int>(k+1,0));
        vector<vector<int>> dp2(sizi+2,vector<int>(k+1,0));

        // Case 1: pick from [0 ... sizi-2]
        for(int index=sizi-2; index>=0; index--){
            for(int n=1; n<=k; n++){
                int include = slices[index] + dp1[index+2][n-1];
                int exclude = dp1[index+1][n];
                dp1[index][n] = max(include, exclude);  // ✅ fix: use [n], not [sizi]
            }
        }
        int case1 = dp1[0][k];

        // Case 2: pick from [1 ... sizi-1]
        for(int index=sizi-1; index>=1; index--){
            for(int n=1; n<=k; n++){
                int include = slices[index] + dp2[index+2][n-1];
                int exclude = dp2[index+1][n];
                dp2[index][n] = max(include, exclude);  // ✅ fix: use [n], not [sizi]
            }
        }
        int case2 = dp2[1][k];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};
//SO
class Solution {
public:
    int solve(vector<int>& slices){
        int sizi=slices.size();
        int k = sizi/3; 
        vector<int> prev1(k+2,0);
        vector<int> curr1(k+2,0);
        vector<int> next1(k+2,0);

        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);

               
        for(int index=sizi-2; index>=0; index--){
            for(int n=1; n<=k; n++){
                int include = slices[index] + next1[n-1];
                int exclude = curr1[n];
                prev1[n] = max(include, exclude);  
            }
            next1=curr1;
            curr1=prev1;
        }
        int case1 =curr1[k];

        for(int index=sizi-1; index>=1; index--){
            for(int n=1; n<=k; n++){
                int include = slices[index] + next2[n-1];
                int exclude = curr2[n];
                prev2[n] = max(include, exclude);  
            }
            next2=curr2;
            curr2=prev2;
        }
        int case2 =curr2[k];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
    }
};
