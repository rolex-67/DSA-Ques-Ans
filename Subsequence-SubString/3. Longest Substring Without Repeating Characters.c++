class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> charMap;
        int left=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(charMap.count(s[i])==0 || charMap[s[i]]<left){
                charMap[s[i]]=i;
                maxlen=max(maxlen,i-left+1);
            }
            else{
                left=charMap[s[i]]+1;
                charMap[s[i]]=i;
            }
        }
        return maxlen;
    }
};
