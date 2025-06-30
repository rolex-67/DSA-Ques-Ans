// User function template for C++

class Solution {
  public:
    // Function to find elements in the array that are equal to their index.
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> ans;
        for(int i=1;i<=arr.size();i++){
            if(arr[i-1]==i){
                ans.push_back(i);
            }
       }
       return ans;
    }
};
