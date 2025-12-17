//S.O.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0) return "";

        int start = 0, maxlen = 1;

        for(int i = 0; i < n; i++){
            // odd length palindrome
            expand(s, i, i, start, maxlen);

            // even length palindrome
            expand(s, i, i + 1, start, maxlen);
        }

        return s.substr(start, maxlen);
    }

    void expand(string &s, int left, int right, int &start, int &maxlen){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            if(right - left + 1 > maxlen){
                start = left;
                maxlen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

//Recusrion
class Solution {
public:
int maxlen=0,end=0,start=0;
    bool isPalindrome(string s,int i,int j){
        while(i<j){
        if(s[i] !=s[j]){
            return false;
            
        }
        i++;
        j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)==true){
                    if((j-i+1)>maxlen){
                        maxlen=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};
