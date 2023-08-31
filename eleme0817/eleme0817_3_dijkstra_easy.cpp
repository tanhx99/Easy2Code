// 小红在第三新北林市的学园城送外卖，学园城中有非常多的学校，学园城里有一个美食街。小红每次会接一些同一个学校的订单，然后从美食街取餐出发，再骑车将外卖送到学校，最后回到美食街，以此往复。
// 学园城有n个结点，m 条道路，美食街为1号结点，剩下的结点都是学校，保证学园城中所有结点连通。给出小红每次要送外卖的学校，请计算小红最少需要骑行的距离。

// 输入描述
// 第一行输入三个整数n,m,p(1<=n,m,p<=10^5)，分别表示结点数、道路数、送外卖次数。
// 接下来 m行，每行输入三个整数u,v(1<=u,v<=n,u≠v) ,w(1<=w<=10^4) 表示结点u和v之间有一条长度为w的道路。
// 最后一行输入q个整数表示每次送外卖的学校a(2<=ai<=n) 。

// 输出描述
// 输出一个整数表示答案。

// 示例1
// 输入
// 3 2 2
// 1 2 1
// 1 3 2
// 2 3

// 输出
// 6

#include <iostream>
#include <vector>

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