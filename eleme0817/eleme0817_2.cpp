// 小红拿到了一个字符串s，她准备构造一个和t长度相同的字符串t：满足以下条件：
// 1.t的字符集和s的相同（去重后的，也就是说不考虑数量）
// 2.t的每个位置的字符都和s不同。
// 例如若 s="aabbc"，那么t可以构造为"cbaca"。
// 你能帮帮小红吗？

// 输入描述
// 输入一个仅由小写字母组成的字符串s，长度不超过 200000。

// 输出描述
// 如果无解，请输出 -1。否则输出任意合法的字符串。

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    unordered_set<char> charSet;
    for (char c: s) {
        charSet.insert(c);
    }
    string t(s.length(), '\0');
    unordered_set<char> usedChars;

    for (int j = 0; j < s.length(); j++) {
        if (usedChars.size() != charSet.size()) {
            for (char c: charSet) {
                if (!usedChars.count(c) && c != s[j]) {
                    t[j] = c;
                    usedChars.insert(c);
                    break;
                }
            }
        } else {
            for (char c: charSet) {
                if (c != s[j]) {
                    t[j] = c;
                    break;
                }
            }
        }
    }
    cout << t << endl;
    return 0;
}