class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int first=-1,last=-1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(x==arr[i] && arr[i-1]!=arr[i]){
                first=i;
            }
            if(x==arr[i] && arr[i+1]!=arr[i]){
                last=i;
            }
        }
        return {first,last};
        
    }
};
