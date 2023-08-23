// 约瑟夫环

// 有n个人围成一圈,顺序排号。从第一个人开始报数（从1到3报数),凡报到3的人退出圈子，问最后留下的是原来第几号的那位。
// 输入描述
// 8个人为成一圈,顺序编号1,2,3,4,5,6,7,8
// 输出描述
// 最后留下的是原来的第7号
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int pos = 0;
    for (int i = 2; i <= n; i++) {
        pos = (pos + 3) % i;
    }
    cout << pos + 1 << endl;
}