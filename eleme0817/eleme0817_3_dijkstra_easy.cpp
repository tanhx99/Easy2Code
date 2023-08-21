#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<int>> &graph, int startNode, vector<int> &distances) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    distances[startNode] = 0;
    for (int i = 0; i < numNodes - 1; ++i) {
        int minDistance = INT_MAX;
        int minNode = -1;
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                minNode = j;
            }
        }
        if (minNode == -1) {
            break; // 所有节点都已访问过或不可达
        }
        visited[minNode] = true;
        for (int j = 0; j < numNodes; ++j) {
            if (!visited[j] && graph[minNode][j] != INT_MAX) {
                distances[j] = min(distances[j], distances[minNode] + graph[minNode][j]);
            }
        }
    }
}


int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1][v - 1] = min(adj[u - 1][v - 1], w);
        adj[v - 1][u - 1] = min(adj[v - 1][u - 1], w);
    }
    vector<int> dist(n, INT_MAX);
    dijkstra(adj, 0, dist);
    int ans = 0, x;
    while (q--) {
        cin >> x;
        ans += 2 * dist[x - 1];
    }
    cout << ans << endl;
}