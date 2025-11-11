// User function Template for C++

class Solution {
  public:
    static bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
        if(a.first.second==b.first.second){
            return a.second<b.second;
        }
        return a.first.second<b.first.second;
    }
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<pair<pair<int,int>,int>> order;
        for(int i=0;i<N;i++){
            order.push_back({{S[i],F[i]},i+1});
        }
        sort(order.begin(),order.end(),cmp);
        vector<int> ans;
        int ansend= -1;
        for(int i=0;i<N;i++){
            if(order[i].first.first>ansend){
                ans.push_back(order[i].second);
                ansend=order[i].first.second;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
