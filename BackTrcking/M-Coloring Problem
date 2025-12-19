class Solution {
  public:
   bool isSafe(int c,int n,vector<int>&color,vector<vector<int>>&adjList){
       
       for(auto it : adjList[n]){
           if(color[it]==c) return false;
       }
       return true;
   }
    bool dfs(vector<vector<int>>&adjList, int m , int v ,vector<int>&color,int node ){
        if(v==node) return true;
       
       for(int i = 1 ;i <= m ;i++){
           
           if(isSafe(i,node,color,adjList)){
               color[node] = i;
               if(dfs(adjList,m,v,color,node+1)) return true;
               color[node] = 0;
           }
       }
       return false;
        
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
       
        
        vector<vector<int>>adjList(v);
        
        
        
        for( auto it : edges){
            
           
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
       
        vector<int>color(v,-1);
         return dfs(adjList,m,v,color,0);
        
        
        
        
    }
};
