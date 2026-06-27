#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MAXN = 5005;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;
const int BASE = 31;

ll pow1[MAXN], inv1[MAXN];
ll pow2[MAXN], inv2[MAXN];

ll modpow(ll a, ll b, ll mod) {
    ll r = 1;
    while (b) {
        if (b & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return r;
}

void prepare_pow_inv(int maxn) {
    pow1[0] = 1;
    pow2[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        pow1[i] = (pow1[i-1] * BASE) % MOD1;
        pow2[i] = (pow2[i-1] * BASE) % MOD2;
    }
    ll invBase1 = modpow(BASE, MOD1 - 2, MOD1);
    ll invBase2 = modpow(BASE, MOD2 - 2, MOD2);
    inv1[0] = 1;
    inv2[0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        inv1[i] = (inv1[i-1] * invBase1) % MOD1;
        inv2[i] = (inv2[i-1] * invBase2) % MOD2;
    }
}

inline ull packHash(ll h1, ll h2) {
    // cả h1,h2 < 2^32, gói vào ull
    return ( (ull)h1 << 32 ) ^ (ull)h2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    int n;
    cin >> n;
    vector<string> dict(n);
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        cin >> dict[i];
        maxLen = max(maxLen, (int)dict[i].size());
    }

    // chuẩn bị pow/inv đến độ dài cần (s.size() và từ dài nhất)
    int upto = max((int)s.size(), maxLen) + 5;
    prepare_pow_inv(upto);

    // lưu hash của các từ (double hash)
    unordered_set<ull> H;
    H.reserve(n * 2);
    vector<int> lensVec;
    lensVec.reserve(n);
    {
        unordered_set<int> lensSet;
        for (auto &w : dict) {
            ll h1 = 0, h2 = 0;
            for (int i = 0; i < (int)w.size(); ++i) {
                int val = (w[i] - 'a' + 1);
                h1 = (h1 + val * pow1[i]) % MOD1;
                h2 = (h2 + val * pow2[i]) % MOD2;
            }
            H.insert(packHash(h1, h2));
            if (!lensSet.count((int)w.size())) {
                lensSet.insert((int)w.size());
                lensVec.push_back((int)w.size());
            }
        }
        sort(lensVec.begin(), lensVec.end());
    }

    // prefix rolling for s
    int L = s.size();
    vector<ll> pre1(L+1, 0), pre2(L+1, 0);
    for (int i = 0; i < L; ++i) {
        int val = (s[i] - 'a' + 1);
        pre1[i+1] = (pre1[i] + val * pow1[i]) % MOD1;
        pre2[i+1] = (pre2[i] + val * pow2[i]) % MOD2;
    }

    auto get_sub_hash = [&](int a, int b)->ull { // inclusive [a..b], 0-based
        ll r1 = (pre1[b+1] - pre1[a]) % MOD1;
        if (r1 < 0) r1 += MOD1;
        r1 = (r1 * inv1[a]) % MOD1;
        ll r2 = (pre2[b+1] - pre2[a]) % MOD2;
        if (r2 < 0) r2 += MOD2;
        r2 = (r2 * inv2[a]) % MOD2;
        return packHash(r1, r2);
    };

    const int MODANS = 1000000007; // theo đề
    vector<int> dp(L+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= L; ++i) {
        for (int len : lensVec) {
            if (len > i) break;
            int start = i - len;
            ull h = get_sub_hash(start, i-1);
            if (H.find(h) != H.end()) {
                dp[i] += dp[start];
                if (dp[i] >= MODANS) dp[i] -= MODANS;
            }
        }
    }
    cout << dp[L] % MODANS << "\n";
    return 0;
}
