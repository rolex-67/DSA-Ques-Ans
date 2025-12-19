class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>> valwithIndex;
        for(int i=0;i<n;i++){
            valwithIndex.push_back({nums[i],i});
        }
        sort(valwithIndex.begin(),valwithIndex.end(),greater<pair<int,int>> ());
        vector<pair<int,int>> topK;
        for(int i=0;i<k;i++){
            topK.push_back(valwithIndex[i]);
        }
        sort(topK.begin(),topK.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second<b.second;
        });
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(topK[i].first);
        }
        return ans;
    }
};
