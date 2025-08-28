class Solution {
public:
    int solve(vector<vector<int>>& envelopes,int n){
        vector<int> heights;
        for(auto &e: envelopes){
            heights.push_back(e[1]);
        }
        vector<int> ans;
        for(int i:heights){
            auto index=lower_bound(ans.begin(),ans.end(),i);
            if(index==ans.end()){
                ans.push_back(i);
            }
            else{
                *index=i;
            }
        }
        return ans.size();
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int n=envelopes.size();
        return solve(envelopes,n);
    }
};
