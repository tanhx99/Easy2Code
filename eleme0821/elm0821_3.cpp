//
// Created by 谭海鑫 on 2023/8/21.
//
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


int main() {
    int n;
    cin >> n;
    int center = n / 2;
    string s1, s2;
    cin >> s1 >> s2;

    unordered_map<int, unordered_set<char>> umap;
    for (int i = center, j = center; j >= 0, i < n; i++, j--) {
        umap[i - center].insert(s1[i]);
        umap[i - center].insert(s2[i]);
        umap[center - j].insert(s1[j]);
        umap[center - j].insert(s2[j]);
    }

    int q;
    cin >> q;
    while (q--) {
        char c1, c2;
        cin >> c1 >> c2;

    }
}


