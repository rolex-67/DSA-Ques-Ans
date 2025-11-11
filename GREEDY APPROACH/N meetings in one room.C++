class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=end.size();
        vector<pair<int,int>> order;
        for(int i=0;i<n;i++){
            pair<int,int> p=make_pair(start[i],end[i]);
            order.push_back(p);
        }
        sort(order.begin(),order.end(),cmp);
        int count=1;
        int ansend=order[0].second;
        for(int i=1;i<n;i++){
            if(order[i].first>ansend){
                count++;
                ansend=order[i].second;
            }
        }
        return count;
    }
};
