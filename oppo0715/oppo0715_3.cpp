// 小欧拿到了一个数组，她每次随机选择一个元素，然后将该元素以及其后缀全部删除。
// 已知第i个元素被选到的概率为ai/sum，其中sum为当前数组所有元素之和。
// 小欧想知道，将数组全部删完的期望次数是多少?

// 把这个问题抽象成组合问题，比如1，3，5，7，最后肯定删的是1，那么倒着回溯，列举所有末尾元素是1的组合。

#include <iostream>
#include <vector>
using namespace std;
vector<int> path;  // 存放的是序号
double ans;
void backtracking(const vector<int>& arr, const vector<int>& sum_i, const int n, int startIndex) {
    if (!path.empty() && path.back() == 0) {  // 最后一个元素是第0个元素
        double tmp;
        for (int i = 0; i < path.size(); i++) {
            if (i == 0) tmp = arr[path[i]] * 1.0 / sum_i[n - 1];
            else tmp *= arr[path[i]] * 1.0 / sum_i[path[i - 1] - 1];
        }
        ans += path.size() * tmp;
        return;
    }
    for (int i = startIndex; i >= 0; i--) {
        path.push_back(i);
        backtracking(arr, sum_i, n, i - 1);
        path.pop_back();
    }
}
int main() {
    vector<int> arr = {1, 3, 5, 7};
    path.clear();
    ans = 0;
    int n = arr.size();
    int sum = 0;
    vector<int> sum_i(n, 0); // 前i项和
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sum_i[i] = sum;
    }
    backtracking(arr, sum_i, n, n - 1);
    cout << ans << endl;
    return 0;
}
