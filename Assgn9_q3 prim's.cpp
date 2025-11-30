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

int main() {
    int n = 5;
    vector<vector<Node>> graph(n);

    graph[0] = {{1,2},{3,6}};
    graph[1] = {{0,2},{2,3},{3,8},{4,5}};
    graph[2] = {{1,3},{4,7}};
    graph[3] = {{0,6},{1,8}};
    graph[4] = {{1,5},{2,7}};

    vector<bool> inMST(n, false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (inMST[curr.v]) continue;
        inMST[curr.v] = true;

        cout << curr.v << " (wt=" << curr.w << ")" << endl;

        for (auto &nxt : graph[curr.v]) {
            if (!inMST[nxt.v]) {
                pq.push(nxt);
            }
        }
    }

    return 0;
}
