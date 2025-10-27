class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> store;
        for(auto const& num:nums2){
            while(!st.empty() && num>=st.top()){
                store[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            store[st.top()]=-1;
            st.pop();
        }
        vector<int> ans;
        for(auto const& num:nums1){
            
            ans.push_back(store[num]);
        }
        return ans;
    }
};
