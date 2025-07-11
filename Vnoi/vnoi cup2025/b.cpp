#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    bool ok = m >= n;
    while (n < m) {
        if (m % n) {
            ok = false;
            break;
        }
        int t = __gcd(n, m/n);
        if (t == 1) {
            ok = false;
            break;
        }
        n *= t;
        ans.push_back(t);
    }
    if (ok) {
        cout << (int) ans.size();
        for (auto u : ans) {
            cout << ' ' << u;
        }
        cout << '\n';
    } else cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
