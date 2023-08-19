// 小红拿到了一个数组，她希望进行最多一次操作:将一个元素修改为x。小红想知道，最终的连续子数组最大和最大是多少？
// 输入描述：
// 第一行输入一个正整数t,代表询问次数。
// 对于每次询问,输入两行:
// 第一行输入两个正整数n和x。代表数组的大小，以及小红可以修改成的元素。
// 第二行输入n个正整数a_i，代表小红拿到的数组。

// 输出描述：
// 输出t行,每行输出一个整数,代表连续子数组的最大和。

// 3
// 5 10
// 5 -1 -5 -3 2
// 2 -3
// -5 -2
// 6 10
// 4 -2 -11 -1 4 -1


#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums, int x) {
    int n = nums.size();
    if (nums.empty()) return 0;
    vector<int> dp(n + 1);
    dp[n] = INT_MIN;
    int result = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], 0) + nums[i];
        result = max(result, dp[i]);
    }  // 从右向左求dp
    int s = 0;
    for (int i = 0; i < n; i++) {  // 枚举替换第i个位置
        s = max(s, 0);
        result = max(result, s + x + max(dp[i + 1], 0));
        s += nums[i];
    }
    return result;
}
int main() {
    int t;
    cin >> t;
    int res[t];
    int j = 0;
    while (j < t) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int maxSub = maxSubArray(arr, x);
        res[j++] = maxSub;
    }
    for (int i = 0; i < t; i++) {
        cout << res[i] << endl;
    }
}
