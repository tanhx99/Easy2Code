// 小红在饿了么上面点了一个外卖，饥肠辘辘的她等骑手等得望眼欲穿。
// 已知小红在时刻t1点了外卖，饿了么上面显示预计送达时间为t2，实际送达时间为t3。请你判断外卖是否超时？

// 输入描述
// 第一行输入一个正整数t，代表询问次数。接下来的3*t行，每 3 行代表一次询问：第一行为点外卖的时刻t1，第二行为预计送达时间t2，第三行为实际送达时间t3。
// 保证骑手送外卖的预期花费时间和实际花费时间均不超过 2 小时。
// 1<=t<=100

// 输出描述
// 输出t行。如果超时则输出"Yes"，否则输出"No"。

// 示例1
// 输入
// 3
// 18:00
// 19:05
// 19:05
// 23:00
// 00:21
// 00:23
// 23:05
// 00:05
// 23:58

// 输出
// No
// Yes
// No

#include <bits/stdc++.h>

using namespace std;

int timeToMin(string time) {
    int hours, minutes;
    stringstream ss(time);
    char delim;
    ss >> hours >> delim >> minutes;
    return hours * 60 + minutes;
}

int main() {
    int n;
    string t1, t2, t3;
    cin >> n;
    getchar();
    while (n--) {
        cin >> t1 >> t2 >> t3;
        int t1_m = timeToMin(t1);
        int t2_m = timeToMin(t2);
        int t3_m = timeToMin(t3);
        if (t2_m < t1_m) t2_m += 24 * 60;
        if (t3_m < t1_m) t3_m += 24 * 60;
        if (t3_m <= t2_m) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}