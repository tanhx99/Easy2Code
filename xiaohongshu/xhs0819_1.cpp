//
// Created by 谭海鑫 on 2023/8/19.
//

/*
 * 小红背单词
 *
 * 输入：
 *      5
 *      you
 *      thank
 *      queue
 *      queue
 *      thank
 * 输出：
 *      2
 *
 * */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];

    unordered_map<string, int> umap;
    unordered_set<string> learned;
    int cur = 1;
    for (string& word: words) {
        if (learned.count(word)) continue;
        if (umap.find(word) == umap.end()) umap[word] = 0;
        umap[word]++;
        if (umap[word] == cur) {
            learned.insert(word);
            cur++;
        }
    }

    cout << learned.size() << endl;


}
