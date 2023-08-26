// 小红拿到了一个由小写字母组成的十字，其中组成十字的两个字母段长度相同，
// 且两个字母段相交于正中间,相邻两个字母之间的距离为1。
// 小红想知道,在十字上取两个字母c1和c2，这两个字母沿着十字移动的最短距离是多少?共有q次询问。
// 请注意,如果一个字母在十字中出现了多次,我们只需要找到最短距离的那一对<c1, c2>即可。
/* 输入
5
abcab
ddcdd
3
a b
a d
b e
*/

/* 输出
1
2
-1
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int center = n / 2;
    string a, b;
    cin >> a >> b;
    unordered_map<char, vector<int>> map1, map2;

    unordered_map<char, int> map3, map4;
    for (char i = 'a'; i <= 'z'; ++i) {
        map3[i] = INT_MAX;
        map4[i] = INT_MAX;
    }

    for (int i = 0; i < n; ++i) {
        map1[a[i]].push_back(i);
        map3[a[i]] = min(map3[a[i]], abs(center - i));
    }
    for (int i = 0; i < n; ++i) {
        map2[b[i]].push_back(i);
        map4[b[i]] = min(map4[b[i]], abs(center - i));
    }

    vector<vector<int>> matrix(26, vector<int>(26, INT_MAX));

    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j || map1.find(i) == map1.end() || map1.find(j) == map1.end()) continue;
            vector<int> &posi = map1[i];
            vector<int> &posj = map1[j];
            int k = 0, m = 0;
            int min_distance = INT_MAX;
            while (k < posi.size() && m < posj.size()) {
                int distance = abs(posi[k] - posj[m]);
                min_distance = min(min_distance, distance);
                if (posi[k] < posj[m]) k++;
                else m++;
            }
            matrix[i - 'a'][j - 'a'] = min(matrix[i - 'a'][j - 'a'], min_distance);
            matrix[j - 'a'][i - 'a'] = matrix[i - 'a'][j - 'a'];
        }
    }

    // 把map1换成map2
    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j || map2.find(i) == map2.end() || map2.find(j) == map2.end()) continue;
            vector<int> &posi = map2[i];
            vector<int> &posj = map2[j];
            int k = 0, m = 0;
            int min_distance = INT_MAX;
            while (k < posi.size() && m < posj.size()) {
                int distance = abs(posi[k] - posj[m]);
                min_distance = min(min_distance, distance);
                if (posi[k] < posj[m]) k++;
                else m++;
            }
            matrix[i - 'a'][j - 'a'] = min(matrix[i - 'a'][j - 'a'], min_distance);
            matrix[j - 'a'][i - 'a'] = matrix[i - 'a'][j - 'a'];
        }
    }

    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j) continue;
            if (map1.find(i) != map1.end() && map2.find(j) != map2.end()) {
                int posi = map3[i], posj = map4[j];
                matrix[i - 'a'][j - 'a'] = min(matrix[i - 'a'][j - 'a'], posi + posj);
                matrix[j - 'a'][i - 'a'] = matrix[i - 'a'][j - 'a'];
            }
        }
    }

    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            if (i == j) continue;
            if (map2.find(i) != map2.end() && map1.find(j) != map1.end()) {
                int posi = map4[i], posj = map3[j];
                matrix[i - 'a'][j - 'a'] = min(matrix[i - 'a'][j - 'a'], posi + posj);
                matrix[j - 'a'][i - 'a'] = matrix[i - 'a'][j - 'a'];
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        char c1, c2;
        cin >> c1 >> c2;
        if (matrix[c1 - 'a'][c2 - 'a'] != INT_MAX) {
            cout << matrix[c1 - 'a'][c2 - 'a'] << endl;
        } else {
            cout << -1 << endl;
        }
    }

}
