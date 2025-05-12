#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int minSwapsToEqualSum(const vector<int>& top, const vector<int>& bot) {
    int n = top.size();
    int sumTop = 0, sumBot = 0;
    for (int i = 0; i < n; ++i) {
        sumTop += top[i];
        sumBot += bot[i];
    }

    int diff = sumTop - sumBot;

    if (diff == 0) return 0;
    if (diff % 2 != 0) return -1;

    vector<int> deltas;
    for (int i = 0; i < n; ++i) {
        int delta = 2 * (bot[i] - top[i]);
        if ((diff > 0 && delta < 0) || (diff < 0 && delta > 0)) {
            deltas.push_back(abs(delta));
        }
    }

    sort(deltas.rbegin(), deltas.rend());

    int total = 0, count = 0;
    for (int d : deltas) {
        total += d;
        ++count;
        if (total >= abs(diff)) return count;
    }

    return -1;
}
int main()
{
    cout<<minSwapsToEqualSum({2,2,5,9,6,4,6,7,7,5},{1,3,1,7,3,3,1,6,8,6})<<endl;
}
