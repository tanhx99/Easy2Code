//
// Created by 谭海鑫 on 2023/8/25.
//

/*
 * 构造长度为n、仅由小写字母组成的字符串，其中有且仅有a个'e'，有且仅有b个'le'，有且仅有c个'me'
 * 如果无解，输出-1；否则输出任意一个合法的字符串
 *
 * */

#include <iostream>
using namespace std;


int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int l = 0;
    string s;
    while (c--) {
        s += "me";
        l += 2;
        a--;
    }
    while (b--) {
        s += "le";
        l += 2;
        a--;
    }

    if (a < 0) cout << -1 << endl;
    else {
        while (a--) {
            s += 'e';
            l++;
        }
        if (l > n) cout << -1 << endl;
        else {
            int ll = n - l;
            while (ll--) s += 'a';
            cout << s << endl;
        }
    }
}

