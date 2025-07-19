#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool bit_all_one(ll i, ll l, ll r) {
    ll mask   = 1LL << i;
    ll period = mask << 1;

    ll cycle_start = (l / period) * period;
    ll ones_start  = cycle_start + mask;
    ll ones_end    = cycle_start + period - 1;
    return (l >= ones_start && r <= ones_end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll l, r, k;
        cin >> l >> r >> k;

        bool ok = false;
        for (ll i = 0; i < k; ++i) {
            if (bit_all_one(i, l, r)) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
