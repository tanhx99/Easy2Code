//
// Created by 谭海鑫 on 2023/8/19.
//

/*
 * 小红的回文串
 * 小红有一个字符串，可以进行一下操作若干次。小红想知道在进行操作之后，这个字符串能不能变成回文串
 * 拆分：w -> vv, m -> nn
 * 轴对称：b -> d, p -> q
 * 翻转：b -> q, d -> p, n -> u
 *
 * 输入：
 *      5
 *      wovv
 *      bod
 *      pdd
 *      moom
 *      lalalai
 * 输出：
 *      YES
 *      YES
 *      YES
 *      YES
 *      NO
 *
 * */

#include <iostream>
using namespace std;

bool judge(string& s) {
    int n = s.size();
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] == s[j]) continue;
        else {
            if ((s[i] == 'w' && s[j] == 'v' && s[j-1] == 'v') || (s[i] == 'm' && string("nu").find(s[j]) != string::npos && string("nu").find(s[j-1]) != string::npos)) j--;
            else if ((s[j] == 'w' && s[i] == 'v' && s[i+1] == 'v') || (s[j] == 'm' && string("nu").find(s[i]) != string::npos && string("nu").find(s[i+1]) != string::npos)) i++;
            else if ((string("bdpq").find(s[i]) != string::npos && string("bdpq").find(s[j]) != string::npos) || (string("nu").find(s[i]) != string::npos && string("nu").find(s[j]) != string::npos)) continue;
            else return false;
        }
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (judge(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


