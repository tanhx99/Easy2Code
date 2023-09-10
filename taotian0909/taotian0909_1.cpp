//小红和朋友是在一个数字游戏中进行对战。这个游戏的规则是，
//小红拥有一些数字，朋友拥有一些数字，他们轮流从自己的数字中选择一个并出示给对方。
//朋友的目标是选择一个严格大于小红出示的数字的数字，并将自己的数字加入自己的分数中。
//如果朋友无法找到一个严格大于小红出示的数字，他可以选择跳过这一轮，不获取任何分数
//朋友可以获得的最大积分是多少
//
//一行两个整数 n,m，表示小红和朋友拥有的数字的个数
//一行 n 个整数 ai，表示小红出示的数字。
//一行 m 个整数 bi，表示朋友拥有的数字

/*
输入：
4 4
1 2 3 4
1 4 5 1
输出：9
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int index = m - 1;
    long long result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (index >= 0 && nums2[index] > nums1[i]) {
            result += nums2[index];
            index--;
        }
    }
    cout << result << endl;
    return 0;
}
