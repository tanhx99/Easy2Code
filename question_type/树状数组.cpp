#include <iostream>

using namespace std;

// 树状数组的大小
const int MAXN = 1000;

// 树状数组
int BIT[MAXN + 1];

// lowbit函数
inline int lowbit(int x) {
    return x & -x;
}

// 更新操作：将位置 idx 的值增加 delta
void update(int idx, int delta) {
    while (idx <= MAXN) {
        BIT[idx] += delta;
        idx += lowbit(idx);
    }
}

// 查询操作：查询前缀和，即 [1, idx] 的和
int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // 初始化树状数组
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        update(i, val);
    }

    // 查询前缀和示例
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--) {
        int idx;
        cout << "Enter the index for query: ";
        cin >> idx;  // 这里的下标从 1 开始！
        if (idx < 1 || idx > n) {
            cout << "Invalid index!" << endl;
        } else {
            int result = query(idx);
            cout << "Prefix sum from 1 to " << idx << " is: " << result << endl;
        }
    }

    return 0;
}
