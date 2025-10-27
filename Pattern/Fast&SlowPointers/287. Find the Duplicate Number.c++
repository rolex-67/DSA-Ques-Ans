#include<map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> store;
        for(auto const& i: nums){
            store[i]++;
            if(store[i]>1){
                return i;
            }
        }
        return -1;
        
    }
};
