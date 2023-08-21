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