class Solution {
public:
    int solve(string word1, string word2,int n,int m,int i,int j){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        int ans=0;
        if(word1[i]==word2[j]){
            return solve(word1,word2,n,m,i+1,j+1);
        }
        else{
            //insert
            int insertans=1+solve(word1,word2,n,m,i,j+1);

            //delete
            int deleteans=1+solve(word1,word2,n,m,i+1,j);
            //REPLACE
            int replaceans=1+solve(word1,word2,n,m,i+1,j+1);
            ans=min(insertans,(min(deleteans,replaceans)));
        }
        return ans;


    }
    int minDistance(string word1, string word2) {
        return solve(word1,word2,word1.size(),word2.size(),0,0);
    }
};
