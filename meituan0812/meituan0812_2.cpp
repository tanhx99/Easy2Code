// 有一个环形的公路,上面共有n站,现在给定了顺时针第i到第i＋1站之间的距离（特殊的，也给出了第n站到第1站的距离)。
// 小美想沿着公路第x站走到第y站,她想知道最短的距离是多少?

// 输入描述
// 第一行输入个正整数n,代表站的数量。
// 第二行输入n个正整数a_i,前n - 1个数代表顺时针沿着公路走，i站到第i＋1站之间的距离;最后一个正整数代表顺时针沿着公路走,第n站到第1站的距离。
// 第三行输入两个正整数x和y,代表小美的出发地和目的地。

// 示例1输入：
// 3
// 1 2 2
// 2 3
// 输出：2
// 示例2输入：
// 3
// 1 2 2
// 1 3
// 输出：2

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    long long dis1 = 0, dis2 = 0;
    for (int i = 0; i < n; i++) {
        if (i >= x - 1 && i < y - 1) dis1 += nums[i];
        else dis2 += nums[i];
    }
    cout << min(dis1, dis2) << endl;
}
