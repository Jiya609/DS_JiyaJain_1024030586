#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int v, w;
    bool operator>(const Node& other) const {
        return w > other.w;
    }
};

void dijkstra(int src, vector<vector<Node>>& graph) {
    int n = graph.size();
    vector<int> dist(n, 1e9);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        for (auto &nxt : graph[curr.v]) {
            if (dist[curr.v] + nxt.w < dist[nxt.v]) {
                dist[nxt.v] = dist[curr.v] + nxt.w;
                pq.push({nxt.v, dist[nxt.v]});
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << endl;
}

int main() {
    int n = 5;
    vector<vector<Node>> graph(n);

    graph[0] = {{1,10},{3,5}};
    graph[1] = {{2,1},{3,2}};
    graph[2] = {{4,4}};
    graph[3] = {{1,3},{2,9},{4,2}};
    graph[4] = {{0,7},{2,6}};

    dijkstra(0, graph);
    return 0;
}
