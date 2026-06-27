#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp(const pair<ll,int>& a, const pair<ll,int>& b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll,int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end(), cmp);

    int ans = 1;
    for (int i = 1; i < n; i++)
        if (nums[i].second < nums[i-1].second)
            ans++;

    cout << ans << '\n';
}
