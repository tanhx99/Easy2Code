// 小红是饿了么的蓝骑士,她一共要配送n个订单。
// 小红可以选择将三个订单进行捆绑配送,这样花费的总时间为这三个订单的花费时间最大值加最小值。
// 小红不记得每个订单的时间了，她只记得订单的总时间为k。她想知道,如果她用最优策略进行配送,配送完这些订单需要花费时间
// 的最大值和最小值分别是多少?


#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int max_answer = n - k / 3;
    int min_answer, remain;

    /*
    if (k % 3 == 0) {
        remain = n - k / 3;
        min_answer = k / 3 + remain - remain / 2;
    } else if (k % 3 == 1) {
        remain = n - k / 3 - 1;
        min_answer = k / 3 + 1 + remain - remain / 2;
    } else {
        remain = n - k / 3 - 2;
        min_answer = k / 3 + 2 + remain - remain / 2;
    }
    */

    remain = n - k / 3 - k % 3;
    min_answer = k / 3 + k % 3 + remain - remain / 2;

    cout << max_answer << " " << min_answer << endl;
    return 0;
}