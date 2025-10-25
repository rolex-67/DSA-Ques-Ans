class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<k){
            return 0.0;
        }
        int cursum=0;
        for(int i=0;i<k;i++){
            cursum=cursum+nums[i];
        }
        int maxsum=cursum;
        int startindi=0;
        int endindi=k;
        while(endindi<n){
            cursum=cursum-nums[startindi];
            startindi++;
            cursum=cursum+nums[endindi];
            endindi++;

            maxsum=max(maxsum,cursum);
        }
        return (double)maxsum/k;
    }
};
