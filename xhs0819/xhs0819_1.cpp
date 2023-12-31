//
// Created by 谭海鑫 on 2023/8/19.
//

/*
 * 小红背单词
 * 小红记单词时，如果她记住了i个单词，且背了一个没有记住的新单词i+1次，则她就会记住这个新单词
 * 现在你知道了小红背单词的顺序，请求出小红今天记住了多少个单词
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
