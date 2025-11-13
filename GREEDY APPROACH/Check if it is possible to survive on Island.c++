// User function Template for C++

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        if(M > N) return -1;
        if(S>=7 && (N-M)*6 < M) return -1;
        
        int buyingDays = S - S/7;
        int totalFood = S*M;
        
        int reqDaysToBuy = 0;
        
        if(totalFood%N == 0){
            reqDaysToBuy = totalFood/N;
        } else{
            reqDaysToBuy = (totalFood/N)+1;
        }
        
        if(reqDaysToBuy <= buyingDays) return reqDaysToBuy;
        return -1;
        
    }
};
