#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : graph[u]) {
        if (!visited[v])
            dfsUtil(v, graph, visited);
    }
}

void dfs(int start, vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dfsUtil(start, graph, visited);
}

int main() {
    int n = 5;
    vector<vector<int>> graph(n);

    graph[0] = {1, 2};
    graph[1] = {0, 3};
    graph[2] = {0};
    graph[3] = {1, 4};
    graph[4] = {3};

    dfs(0, graph);
    return 0;
}
