class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int end=numbers.size()-1;
        int start=0;
        while(start<end){
            if(numbers[start]+numbers[end]==target){
                return {start+1,end+1};
            }
            if(numbers[start]+numbers[end]>target){
                end--;
            }
            else{
                start++;
            }
        }
        return {};
        
    }
};
