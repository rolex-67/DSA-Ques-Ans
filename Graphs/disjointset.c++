void make_set(vector<int> &parent,vector<int> &rank,int n){
  for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=0;
  }
}
int findparent(vector<int> &parent,int node){
  if(parent[node]==node){
    return node;
  }
  return parent[node]=findparent(parent,parent[node]);
}

void union_set(int u,int v,vector<int> &parent){
  u=findparent[parent,u];
  v=findparent[parent,v];
  if(rank[u]<rank[v]){
    parent[u]=v;
  }
  else if(rand[v]<rank[u]){
    parent[v]=u;
  }
  else{
    parent[v]=u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
   vector<int> parent(n);
   vector<int> rank(n);
   make_set(parent,rank);
}