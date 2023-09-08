#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 拓扑排序算法
vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0); // 记录每个节点的入度
    vector<int> result; // 存储拓扑排序结果
    queue<int> q;

    // 计算每个节点的入度
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // 将入度为0的节点入队
    for (int u = 0; u < n; ++u) {
        if (inDegree[u] == 0) {
            q.push(u);
        }
    }

    // 开始拓扑排序
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        // 更新相邻节点的入度
        for (int v : adj[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 如果图中有环，返回空向量
    if (result.size() != n) {
        return {};
    }

    return result;
}

int main() {
    int n = 6; // 节点数量
    vector<vector<int>> adj(n); // 邻接表

    // 添加有向边
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(n, adj);

    if (result.empty()) {
        cout << "There is a circle in the graph!" << endl;
    } else {
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
