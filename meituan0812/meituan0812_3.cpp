// 小美有一个矩形的蛋糕,共分成了n行m列，共n×m个区域,每个区域是一个小正方形,
// 已知蛋糕每个区域都有个美味度。她想切一刀把蛋糕切成两部分，自已吃一部分,小团吃另一部分。
// 小美希望两个人吃的部分的美味度之和尽可能接近,请你输出|s1-s2|的最小值。(其中s1代表小美吃的美味度,s2代表小团吃的美味度）
// 请务必保证,切下来的区域都是完整的，即不能把某个小正方形切成两个小区域。

// 示例输入：
// 2 3
// 1 1 4
// 5 1 4
// 输出：0

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    vector<int> rows(n), cols(m);
    vector<long long> rsum(n), csum(m);

    // 求每行每列的和
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            rows[i] += nums[i][j];
            cols[j] += nums[i][j];
        }
    }
    // 行和的前缀和
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += rows[i];
        rsum[i] = sum;
    }
    // 列和的前缀和
    sum = 0;
    for (int j = 0; j < m; j++) {
        sum += cols[j];
        csum[j] = sum;
    }
    long long res = LLONG_MAX;
    // 对 行和的前缀和 进行二分
    int left = 0, right = n - 2;
    long long half = rsum[n - 1] / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (rsum[mid] <= half) left = mid + 1;
        else right = mid - 1;
    }
    // 二分的结果，left = right + 1
    // right应该是小于等于half的最大值，left应该是大于half的最小值
    // 结果只能在这两个里面选，下面列和同理
    long long diff = abs(rsum[n - 1] - rsum[left] - rsum[left]);
    res = min(diff, res);
    diff = abs(rsum[n - 1] - rsum[right] - rsum[right]);
    res = min(diff, res);

    // 对 列和的前缀和 进行二分
    left = 0, right = m - 2;
    half = csum[m - 1] / 2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (csum[mid] <= half) left = mid + 1;
        else right = mid - 1;
    }
    diff = abs(csum[m - 1] - csum[left] - csum[left]);
    res = min(diff, res);
    diff = abs(csum[m - 1] - csum[right] - csum[right]);
    res = min(diff, res);

    // 没用二分版本，遍历i，从i处切开，i属于左面/上面的部分，只能过96.67%
    /* for (int i = 0; i < n - 1; i++) {
        long long diff = abs(rsum[n - 1] - rsum[i] - rsum[i]);
        res = min(diff, res);
    }
    for (int j = 0; j < m - 1; j++) {
        long long diff = abs(csum[m - 1] - csum[j] - csum[j]);
        res = min(diff, res);
    } */

    cout << res << endl;
    return 0;
}
