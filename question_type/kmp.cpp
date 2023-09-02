//
// Created by ̷���� on 2023/8/30.
//

#include <iostream>
using namespace std;

void getNext(int* next, const string& p) {  // ��ȡnext���飨ƥ�䴮��
    int j = 0;
    next[0] = 0;
    for(int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) { // jҪ��֤����0����Ϊ������ȡj-1��Ϊ�����±�Ĳ���
            j = next[j - 1]; // ע�������Ҫ��ǰһλ�Ķ�Ӧ�Ļ���λ����
        }
        if (p[i] == p[j]) {
            j++;
        }
        next[i] = j;
    }
}

int match(string s, string p) { // �ı������Ƿ������ƥ�䴮�������򷵻ص�һ���ַ���λ���±꣬δ�����򷵻�-1
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
    string s = "bacbababaabcbab";   // �ı���
    string p = "ababaa";   // ƥ�䴮�����߽�ģʽ����
    int m = p.size();
    int next[m];
    getNext(next, p);

    cout << "ƥ�䴮p��next���飺";
    for (int idx: next) cout << idx << ' ';
    cout << endl;

    cout << match(s, p) << endl;
}

