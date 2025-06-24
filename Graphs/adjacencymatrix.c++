#include<iostream>
#include<unordered_map>
#include<list>
//template <typenmae T>
using namespace std;
class graph{
public:
    unordered_map<int,list<int>> adj;
    void addedge(int u,int v,bool direction){ //T u,T v,
        ///0=>undirected
        ///1=>directed
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n;
    cout<<"Enter the number of nodes "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the number of edges "<<endl;
    cin>>m;

    graph g; //graph<int>
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addedge(u,v, 0);
    }
    g.printAdjList();
return 0;
}