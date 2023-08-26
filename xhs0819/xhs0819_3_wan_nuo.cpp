// 枚举终点，每次枚举时按照消耗的代价从小到大进行排序。用一个pre数组记录前缀结点的最大价值
// 对于每个终点，从代价由大到小枚举中间点，再利用二分找出这个中间点的相邻点，因为代价是从小排序的，所以价值加上二分找到的点的pre值即可。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct Edge {
    long long value, time;
    Edge(long long value, long long time) : value(value), time(time) {}
};

long long a[maxn];
long long h[maxn];
vector<Edge> E[maxn];
long long res = 0;
long long pre[maxn];

void kaishi(int x) {  // 记录前缀最大值
    int sum = E[x].size();
    pre[0] = E[x][0].value;
    for (int i = 1; i < sum; i++) {
        pre[i] = max(E[x][i].value, pre[i - 1]);
    }
}

int get(int st, long long last) {  // 二分选择最右面的小于等于last的值
    int l = 0, r = E[st].size() - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (E[st][mid].time <= last) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

long long function(int x, long long last) {
    long long ans = 0;
    for (int i = E[x].size() - 1; i > 0; i--) {  // 时间从大到小枚举，这样才能用二分和前缀最大值的结果
        int id = get(x, last - E[x][i].time);
        id = min(id, i - 1);
        if (id < 0) {
            continue;
        }
        ans = max(ans, E[x][i].value + pre[id]);
    }
    return ans;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        if (h[i] <= k) {
            res = max(res, a[i]);
        }
    }
    
    for (int i = 0; i < maxn; i++) {
        E[i] = vector<Edge>();
    }
    
    for (int i = 0; i < m; i++) {
        int from, to, time;
        cin >> from >> to >> time;
        E[from].push_back(Edge(a[to], time + h[to]));
        E[to].push_back(Edge(a[from], time + h[from]));
        if (time + h[from] + h[to] <= k) {
            res = max(res, a[from] + a[to]);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (E[i].size() < 2) {  // 枚举的点是中间的点，至少有两个点能到这个点
            continue;
        }
        sort(E[i].begin(), E[i].end(), [](const Edge& e1, const Edge& e2) {
            return e1.time < e2.time;
        });
        kaishi(i);
        res = max(res, a[i] + function(i, k - h[i]));
    }
    
    cout << res << endl;
    
    return 0;
}
