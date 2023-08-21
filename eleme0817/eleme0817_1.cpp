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