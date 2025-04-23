#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vi vector<int>
#define vll vector<ll>
#define fori(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()

void sol() {
    int sz;
    cin >> sz;
    vector<int> ar(sz);
    map<int, vector<int>> idx;

    int mx = 0;
    fori(i, sz) {
        cin >> ar[i];
        idx[ar[i]].push_back(i);
        if (ar[i] != -1) mx = max(mx, ar[i]);
    }

    for (auto& pr : idx) sort(all(pr.second));

    vector<int> res(sz);
    int val = 1;

    for (int k = 1; k <= mx; ++k) {
        if (!idx.count(k)) continue;
        auto& id = idx[k];
        int ct = id.size();

        if (k % 2) {
            fori(i, ct) res[id[i]] = val + i;
        } else {
            fori(i, ct) res[id[i]] = val + ct - 1 - i;
        }
        val += ct;
    }

    // gán giá trị cuối cùng cho phần tử bị giữ lại (-1)
    if (idx.count(-1)) res[idx[-1][0]] = val;

    fori(i, sz) cout << res[i] << (i == sz - 1 ? "\n" : " ");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) sol();
    return 0;
}
