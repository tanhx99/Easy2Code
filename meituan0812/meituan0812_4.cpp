// 小美拿到了一棵树，每个节点有一个权值。初始每个节点都是白色。小美有若干次操作，每次操作可以选择两个相邻的节点,
// 如果它们都是白色且权值的乘积是完全平方数，小美就可以把这两个节点同时染红。
// 小美想知道,自己最多可以染红多少个节点?
// 输入描述
// 第一行输入一个正教数n,代表节点的数量。
// 第二行输入n个正整数a_i,代表每个节点的权值。
// 接下来的n-1行,每行输入两个正整数u,v，代表节点u和节点v有一条边连接。

// 示例输入：
// 3
// 3 3 12
// 1 2
// 2 3
// 输出：2

// 树形dp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
vector<vector<int>> adj;  // 邻接矩阵，如果节点太多应该换邻接表
vector<int> value;

bool judge(int num) {  // 考虑两个数相乘的结果用long long
    double x = sqrt(num);
    if (floor(x) == x) return true;
    return false;
}

void dfs(int cur, int pre, int n) {

    for (int next = 0; next < n; next++) {
        if (adj[cur][next] == 0 || next == pre) continue;
        dfs(next, cur, n);
    }

    int sum = 0;
    for (int next = 0; next < n; next++) {
        if (adj[cur][next] == 0 || next == pre) continue;
        sum += max(dp[next][0], dp[next][1]);
    }
    dp[cur][0] = sum;

    for (int next = 0; next < n; next++) {
        if (adj[cur][next] == 0 || next == pre) continue;
        if (judge(value[cur] * value[next])) {
            dp[cur][1] = max(dp[cur][1], dp[cur][0] - max(dp[next][0], dp[next][1]) + dp[next][0] + 2);
        }
    }
}

int main() {
    int n;
    cin >> n;
    value.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    adj.resize(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1][y - 1] = 1;
        adj[y - 1][x - 1] = 1;
    }
    dp.resize(n, vector<int>(2));
    dfs(0, -1, n);  // cur, pre, n
    cout << max(dp[0][1], dp[0][0]) << endl;
}
