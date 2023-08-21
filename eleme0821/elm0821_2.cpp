//
// Created by 谭海鑫 on 2023/8/21.
//


#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    int maxCost, minCost;

    if ((n-1)%3 == 0) maxCost = (n-1)/3*2 + k-(n-1);
    else maxCost = (n-1)/3*2 + 1 + k-(n-1);

    if (n%3 == 0) {
        minCost = n / 3;
        double num = (k-n/3) / (n/3.0);
        int m = ceil(num / 2);
        minCost += m * (n/3);
    } else if (n%3 == 1) {
        minCost = (n-1) / 3 + 1;
        double num = (k - ((n-1)/3+1)) / ((n-1)/3.0);
        int m = ceil(num / 2);
        minCost += m * (n-1)/3;
    } else if (n%3 == 2) {
        minCost = (n-2) / 3 + 1;
        double num = (k - ((n-2)/3+1)) / ((n-2)/3.0*2 + 1);
        minCost += floor(num);
        double num2 = (k - ((n-2)/3+1+floor(num))) / ((n-2)/3.0);
        int m = ceil(num2 / 2);
        minCost += m * ((n-2)/3);
    }
    cout << maxCost << ' ' << minCost << endl;
}
