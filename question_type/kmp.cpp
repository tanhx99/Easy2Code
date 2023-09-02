//
// Created by 谭海鑫 on 2023/8/30.
//

#include <iostream>
using namespace std;

void getNext(int* next, const string& p) {  // 获取next数组（匹配串）
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
            j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

int match(string s, string p) { // 文本串中是否出现了匹配串，出现则返回第一个字符的位置下标，未出现则返回-1
    if (p.size() == 0) {
        return 0;
    }
    int next[p.size()];
    getNext(next, p);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != p[j]) {
            j = next[j - 1];
        }
        if (s[i] == p[j]) {
            j++;
        }
        if (j == p.size() ) {
            return i - p.size() + 1;
        }
    }
    return -1;
}


int main() {
    string s = "bacbababaabcbab";   // 文本串
    string p = "ababaa";   // 匹配串（或者叫模式串）
    int m = p.size();
    int next[m];
    getNext(next, p);

    cout << "匹配串p的next数组：";
    for (int idx: next) cout << idx << ' ';
    cout << endl;

    cout << match(s, p) << endl;
}

