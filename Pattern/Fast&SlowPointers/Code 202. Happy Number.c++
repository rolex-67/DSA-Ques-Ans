class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum=sum+d*d;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 && !seen.count(n)){
            seen.insert(n);
            n=solve(n);
        }
        return n==1;
    }
};
