#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 998244353;

// Hàm tính lũy thừa modulo
ll modexp(ll x, ll e = P - 2) {
    ll res = 1;
    while (e) {
        if (e & 1) res = res * x % P;
        x = x * x % P;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int N = 1 << m;

        vector<ll> Splus(m, 1), Sminus(m, 1);

        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            int len = r - l + 1;

            for (int b = 0; b < m; ++b) {
                ll full = len >> (b + 1);
                ll rem = len & ((1 << (b + 1)) - 1);
                ll ones = full * (1LL << b) + max(1LL*0, rem - (1 << b));
                ll zeros = len - ones;

                ll a = (zeros + ones) % P;
                ll d = (zeros - ones) % P; if (d < 0) d += P;

                Splus[b] = Splus[b] * a % P;
                Sminus[b] = Sminus[b] * d % P;
            }
        }

        ll inv2 = (P + 1) / 2;
        vector<ll> A(m), B(m);
        for (int b = 0; b < m; ++b) {
            A[b] = (Splus[b] + Sminus[b]) % P * inv2 % P;
            B[b] = (Splus[b] - Sminus[b] + P) % P * inv2 % P;
        }

        vector<ll> f(N);
        f[0] = 1;
        for (int b = 0; b < m; ++b) {
            int step = 1 << b;
            for (int mask = 0; mask < N; mask += (step << 1)) {
                for (int t = 0; t < step; ++t) {
                    ll v0 = f[mask + t] * A[b] % P;
                    ll v1 = f[mask + t] * B[b] % P;
                    f[mask + t] = v0;
                    f[mask + t + step] = v1;
                }
            }
        }

        ll pw2 = 1;
        int h = 0;
        for (int x = 0; x < N; ++x) {
            ll gx = f[x] * pw2 % P;
            h ^= (int)gx;
            pw2 = pw2 * 2 % P;
        }

        cout << h << "\n";
    }

    return 0;
}
