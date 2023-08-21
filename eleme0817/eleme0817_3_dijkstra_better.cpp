#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }

    vector<int> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i];
    }

    vector<int> dis(n + 1, INT_MAX);
    vector<bool> vst(n + 1, false);
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto arr = pq.top();
        pq.pop();
        int d = arr.first, u = arr.second;
        if (vst[u]) continue;
        vst[u] = true;
        for (const auto& A : graph[u]) {
            int v = A.first, w = A.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    long long ans = 0;
    for (int i : Q) {
        ans += static_cast<long long>(dis[i]) * 2;
    }

    cout << ans << endl;

    return 0;
}