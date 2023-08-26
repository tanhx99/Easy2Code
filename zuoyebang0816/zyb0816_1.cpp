//
// Created by 谭海鑫 on 2023/8/25.
//
/*
 * 最长的斐波那契子序列的长度（力扣873）
 *
 * */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int lenLongestFibSubseq(vector<int> &arr) {
    unordered_map<int, int> umap;
    int n = arr.size();
    for (int i = 0; i < n; i++) umap[arr[i]] = i;
    vector <vector<int>> dp(n, vector<int>(n));
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] * 2 > arr[i]; j--) {
            int k = -1;
            if (umap.count(arr[i] - arr[j])) k = umap[arr[i] - arr[j]];
            if (k >= 0) dp[j][i] = max(dp[k][j] + 1, 3);
            ans = max(ans, dp[j][i]);
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    cout << lenLongestFibSubseq(nums) << endl;
}
