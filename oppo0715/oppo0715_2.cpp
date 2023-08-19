// 小欧拿到了一个字符串，她每次会对一个区间[l,r]内出现次数最多的字符进行大小写翻转(大写和小写视为不同的字符),如果有多种不同的字符出现次数都最小欧会把这些字符全部翻转。小欧希望你在每次操作后输出当前的字符串，你能帮帮她吗?

// 输入描述：
// 第一行输入两个正教数n,q,代表字符串的大小以及操作次数。
// 第二行输入一个长度为n的、仅包含大小写字母的字符串。
// 接下来的q行，每行输入两个正整数l,r，代表一次操作。

// 输出描述：
// 输出q行,每行输出个字符串,代表当前操作结束时的字符串,

// 每次操作直接修改上一次操作后得到的字符串。

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<string> res;
    while (q--) {
        int l, r;
        cin >> l >> r;
        vector<int> freq(52, 0);
        for (int i = l - 1; i <= r - 1; i++) {
            if (islower(s[i])) {
                freq[s[i] - 'a']++;
            } else {
                freq[s[i] - 'A' + 26]++;
            }
        }
        int max = *max_element(freq.begin(), freq.end());
        for (int i = l - 1; i <= r - 1; i++) {
            if (islower(s[i]) && freq[s[i] - 'a'] == max) {
                s[i] = toupper(s[i]);
            } else if (isupper(s[i]) && freq[s[i] - 'A' + 26] == max) {
                s[i] = tolower(s[i]);
            }
        }
        res.push_back(s);
    }
    for (string x: res) {
        cout << x << endl;
    }
    return 0;
}
