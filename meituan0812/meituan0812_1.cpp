
// 小美拿到了一个排列。她想知道在这个排列中,x和y是否是相邻的。你能帮帮她吗?
// 排列是指一个长度为n的数组，其中1到n每个元素恰好出现一次。
// 输入描述
// 第一行输入一个正整数n,代表排列的长度。第二行输入n个正整数a_i,代表排列的元素。
// 第三行输入两个正整数x和y,用空格隔开。

// 示例1输入：
// 4
// 1 4 2 3
// 2 4
// 输出：Yes
// 示例2输入：
// 5
// 3 4 5 1 2
// 3 2
// 输出：No

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int x, y;
    cin >> x >> y;
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if ((nums[i] == x && nums[i + 1] == y) || (nums[i] == y && nums[i + 1] == x)) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
