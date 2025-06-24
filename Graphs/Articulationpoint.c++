#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
using namespace std;
int min(int a,int b){
    if(a<b){
        return  a;
    }
    return b;
}
void dfs(int node,int parent,vector<int> &discoverytime,vector<int> &earliesttime,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjlist,vector<int> &result,int &timer){

    visited[node]=true;
    discoverytime[node]=earliesttime[node]=timer++;
    int child=0;
    for(auto neighbour: adjlist[node]){
        if(neighbour==parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour,node,discoverytime,
                earliesttime,visited,adjlist, result, timer);
            earliesttime[node]=min(earliesttime[node],earliesttime[neighbour]);
            if(earliesttime[neighbour]>= discoverytime[node] && parent!=-1){
                result[node]=true;
            }
            child++;
            }
        else{
            earliesttime[node]=min(earliesttime[node],discoverytime[neighbour]);
        }
    }
    if(parent==-1 && child>1){
        result[node]=1;
    }
}
int main(){
    int n=5;
    int e=5;
    vector<pair<int,int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    unordered_map<int,list<int>> adjlist;
    for(int i=0;i<edges.size();i++){
        int u =edges[i].first;
        int v=edges[i].second;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);

    }
    int timer=0;
    vector<int> discoverytime(n);
    vector<int> earliesttime(n);
    unordered_map<int,bool> visited;
    int parent=-1;
    vector<int> result(n,0);
    for(int i=0;i<n;i++){
        discoverytime[i]=-1;
        earliesttime[i]=-1;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,-1,discoverytime,earliesttime,visited,adjlist,result,timer);
        }
    }
    cout<<"Articulation Points are as follows"<<endl;
    for(int i=0;i<n;i++){
        if(result[i]!=0){
            cout<<i<< " ";
        }
    }
return 0;
}