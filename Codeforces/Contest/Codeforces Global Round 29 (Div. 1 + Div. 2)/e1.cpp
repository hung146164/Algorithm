#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll B;
        cin >> n >> B;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll OR0 = 0;
        for (ll x : a) OR0 |= x;
        int base = __builtin_popcountll(OR0);

        // Tìm bit còn thiếu
        vector<int> missing_bits;
        for (int b = 0; b < 31; b++) {
            if (((OR0 >> b) & 1) == 0) missing_bits.push_back(b);
        }
        int M = missing_bits.size();

        if (M == 0) {
            cout << base << "\n";
            continue;
        }

        // dp[mask] = min cost
        vector<ll> dp(1 << M, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            vector<pair<ll,int>> options;
            options.push_back({0, 0}); // giữ nguyên

            // sinh các candidate tăng a[i]
            for (int b = 0; b < 31; b++) {
                ll cur = (a[i] >> b);
                ll target = (cur + 1) << b;
                ll cost = target - a[i];
                if (cost > B) continue;

                ll newVal = target;
                int gainMask = 0;
                for (int k = 0; k < M; k++) {
                    int bit = missing_bits[k];
                    if (((newVal >> bit) & 1) && !((a[i] >> bit) & 1)) {
                        gainMask |= (1 << k);
                    }
                }
                options.push_back({cost, gainMask});
            }

            vector<ll> newdp = dp;
            for (int mask = 0; mask < (1 << M); mask++) {
                if (dp[mask] >= INF) continue;
                for (auto [cst, gmask] : options) {
                    int nmask = mask | gmask;
                    newdp[nmask] = min(newdp[nmask], dp[mask] + cst);
                }
            }
            dp.swap(newdp);
        }

        int ans = base;
        for (int mask = 0; mask < (1 << M); mask++) {
            if (dp[mask] <= B) {
                ans = max(ans, base + __builtin_popcount(mask));
            }
        }
        cout << ans << "\n";
    }
}

