//
// Created by 谭海鑫 on 2023/8/20.
//

/*
 * 小红的旅游攻略
 * n个景点，m条路线，每个景点的攻略价值为a，要花费h时间浏览，不同景点之间的交通时间为w。
 * 小红最多会选择3个相邻的景点，然后按顺序将景点写入攻略。
 * 她需要保证每个景点的浏览时间加上景点之间的交通时间总和不超过k，并使得攻略的价值尽可能大，即景点的总价值尽可能大。
 * 求小红攻略的最大价值
 *
 * 输入：第一行n, m, k；第二行n个整数表示数组a；第三行n个整数表示数组h；接下来的m行，每行三个整数u, v, w，表示景点u, v之间的交通时间为w
 *      4 4 8
 *      4 3 2 1
 *      1 2 3 4
 *      1 2 1
 *      2 3 1
 *      2 4 1
 *      3 4 1
 * 输出：
 *      9
 *
 * */

#include <iostream>
#include <vector>
using namespace std;

void dfs(int cur, vector<vector<int>>& graph, vector<int>& a, vector<int>& h, int curk, int k, int cura, int& ans, int num, vector<bool>& visited) {
    curk += h[cur];
    cura += a[cur];
    num--;
    visited[cur] = true;

    if (curk > k) return;
    if (!num) {
        ans = max(ans, cura);
        return;
    }
    for (int i = 0; i < graph[cur].size(); i++) {
        if (i == cur || visited[i] || graph[cur][i] == 0) continue;
        curk += graph[cur][i];
        dfs(i, graph, a, h, curk, k, cura, ans, num, visited);
        curk -= graph[cur][i];
    }
    num++;
    visited[cur] = false;
    curk -= h[cur];
    cura -= a[cur];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1][v-1] = graph[v-1][u-1] = w;
    }

    int ans = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        dfs(i, graph, a, h, 0, k, 0, ans, 3, visited);
    }
    cout << ans << endl;
}

