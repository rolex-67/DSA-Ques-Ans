class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> stor
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        };
        int ans=0;
        for(int i=0;i<n;i++){
            if(prefix[i]==k){
                ans++;
            }
            if(store.find(prefix[i]-k) != store.end()){
                ans=ans+store[prefix[i]-k];
            }
            store[prefix[i]]++;
        }
        return ans;
    }
};


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int ans=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int sum=nums[i];
//             if(sum==k){
//                 ans++;
//             }
//             for(int j=i+1;j<n;j++){
//                 sum=sum+nums[j];
//                 if(sum==k){
//                    ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };
