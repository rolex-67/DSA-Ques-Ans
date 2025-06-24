#include <unordered_map>
#include <stack>
#include <list>
#include <vector>
using namespace std;

// Corrected: dfs function was wrongly referred as bfs in your original code
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adjlist) {
    visited[node] = true;
    for (auto neighbour : adjlist[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, visited, st, adjlist);
        }
    }
    // topo logic
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjlist) {
    visited[node] = true;
    for (auto neighbour : adjlist[node]) {
        if (!visited[neighbour]) {  // Corrected: was checking node again instead of neighbour
            revdfs(neighbour, visited, adjlist);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adjlist;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v_ = edges[i][1];  // Renamed v to v_ to avoid shadowing the outer 'v'
        adjlist[u].push_back(v_);
    }

    // Topo sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++) {  // Corrected: added missing `int`
        if (!visited[i]) {
            dfs(i, visited, st, adjlist);
        }
    }

    // Transpose
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        visited[i] = false;
        for (auto neighbour : adjlist[i]) {
            transpose[neighbour].push_back(i);
        }
    }

    // DFS on transposed graph
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!visited[top]) {
            count++;
            revdfs(top, visited, transpose);  // Corrected: removed 'st' from argument, it?s not used in revdfs
        }
    }
    return count;
}
