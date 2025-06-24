#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
void dfs(int node ,int parent,int timer,vector<int> &discoverytime,vector<int> &earliesttime,vector<vector<int>> &result,unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited){
    visited[node]=true;
    discoverytime[node]=earliesttime[node]=timer++;
    for(auto neighbour: adjlist[node]){
        if(neighbour==parent)
            continue; 
        if(!visited[neighbour]){
            dfs(neighbour,node,timer,discoverytime,earliesttime,result,adjlist,visited);
            earliesttime[node]=min(earliesttime[node],earliesttime[neighbour]);
            //check the edge is bridge
            if(earliesttime[neighbour]>discoverytime[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else{
            //back edge
            earliesttime[node]=min(earliesttime[node],discoverytime[neighbour]);

        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    int timer=0;
    vector<int> discoverytime(v);
    vector<int> earliesttime(v);
    int parent=-1;
    unordered_map<int,bool> visited;
    for(int i=0;i<v;i++){
        discoverytime[i]=-1;
        earliesttime[i]=-1;
    }
    vector<vector<int>> result;
    //dfs
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,discoverytime,earliesttime,result,adjlist,visited);
        }
    }
    return result;
}
