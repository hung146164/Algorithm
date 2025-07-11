#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 998244353;
const ll MAX = 65;

ll pow2[MAX];

void mu2() {
    pow2[0] = 1;
    for (ll i = 1; i < MAX; ++i) {
        pow2[i] = (1LL* pow2[i - 1] * 2) % MOD;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mu2();
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> p(n), q(n), a(n), b(n);

        for (ll i = 0; i < n; ++i) cin >> p[i];
        for (ll i = 0; i < n; ++i) cin >> q[i];

        for (ll i = 0; i < n; ++i) {
            a[i] = pow2[p[i]];
            b[i] = pow2[q[i]];
        }

        vector<ll> r(n);
        for (ll i = 0; i < n; ++i) {
            ll max_val = 0;
            for (ll j = 0; j <= i; ++j) {
                max_val = max(max_val, (a[j] + b[i - j]) % MOD);
            }
            r[i] = max_val;
        }

        for (ll i = 0; i < n; ++i)
            cout << r[i] << " ";
        cout << "\n";
    }
}
