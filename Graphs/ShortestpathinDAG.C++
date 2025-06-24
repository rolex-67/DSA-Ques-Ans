#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<unordered_map>

using namespace std;
class graph {
    public:
    unordered_map<int,list<pair<int,int>>> adjlist;
    void addedge(int u,int v,int weight){
        pair<int,int> p=make_pair(v,weight);
        adjlist[u].push_back(p);

    }
    void printadjlist(){
        for(auto i:adjlist){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<"(" <<j.first<<","<<j.second<<")";
            }cout <<endl;
        }

    }
};



int main(){
    graph g;
    g.addedge(0,1,5);
    g.addedge(0,2,3);
    g.addedge(1,2,2);
    g.addedge(1,3,6);
    g.addedge(2,3,7);
    g.addedge(2,4,4);
    g.addedge(2,5,2);
    g.addedge(3,4,-1);
    g.addedge(4,5,2);
    g.printadjlist();
    int n=6;
    stack<int> s;

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        
    }


return 0;
}