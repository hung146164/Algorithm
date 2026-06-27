#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query { int l, r, id; };

ll modpow(ll a, ll e, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll p;
    if (!(cin >> p)) return 0;
    string s; cin >> s;
    int n = (int)s.size();
    int q; cin >> q;

    // Special-case p == 2 or p == 5 (10 and p not coprime => inverse of 10 doesn't exist)
    if (p == 2 || p == 5) {
        // prefix counts of "good" ending digits and sum of their indices
        vector<ll> prefCnt(n+1, 0), prefIdx(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            int d = s[i-1] - '0';
            bool good = (p == 2) ? (d % 2 == 0) : (d == 0 || d == 5);
            prefCnt[i] = prefCnt[i-1] + (good ? 1 : 0);
            prefIdx[i] = prefIdx[i-1] + (good ? i : 0);
        }
        while (q--) {
            int a, b; cin >> a >> b;
            ll cnt = prefCnt[b] - prefCnt[a-1];
            ll sumIdx = prefIdx[b] - prefIdx[a-1];
            // sum over good positions j in [a..b] of (j - (a-1)) = sumIdx - (a-1)*cnt
            ll ans = sumIdx - (ll)(a-1) * cnt;
            cout << ans << '\n';
        }
        return 0;
    }

    // General case: p is prime and gcd(10, p) = 1, we can use inverse of 10
    ll inv10_base = modpow(10, p - 2, p);
    vector<ll> inv10(n + 1);
    inv10[0] = 1;
    for (int i = 1; i <= n; ++i) inv10[i] = (inv10[i-1] * inv10_base) % p;

    // prefix mod
    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i-1] * 10 + (s[i-1] - '0')) % p;
    }

    // normArr[i] = prefix[i] * inv10[i] % p  for i = 0..n
    vector<ll> normArr(n + 1);
    for (int i = 0; i <= n; ++i) {
        normArr[i] = (prefix[i] * inv10[i]) % p;
        if (normArr[i] < 0) normArr[i] += p;
    }

    // coordinate compression
    vector<ll> vals = normArr;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int)vals.size();
    vector<int> comp(n + 1);
    for (int i = 0; i <= n; ++i) comp[i] = int(lower_bound(vals.begin(), vals.end(), normArr[i]) - vals.begin());

    // read queries as [a-1, b] on normArr indices
    vector<Query> queries;
    queries.reserve(q);
    for (int i = 0; i < q; ++i) {
        int a, b; cin >> a >> b;
        queries.push_back({a - 1, b, i});
    }

    // MO sort
    int block = max(1, (int)(sqrt(n + 1)));
    sort(queries.begin(), queries.end(), [&](const Query &A, const Query &B) {
        int ba = A.l / block, bb = B.l / block;
        if (ba != bb) return ba < bb;
        return (ba & 1) ? (A.r > B.r) : (A.r < B.r);
    });

    // MO process with freq array
    vector<ll> ans(q, 0);
    vector<ll> freq(m, 0);
    ll curAns = 0;
    int curL = 0, curR = -1;

    auto add = [&](int idx) {
        int id = comp[idx];
        curAns += freq[id];
        freq[id] ++;
    };
    auto remove_ = [&](int idx) {
        int id = comp[idx];
        freq[id] --;
        curAns -= freq[id];
    };

    for (auto &qq : queries) {
        int L = qq.l, R = qq.r;
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curL < L) remove_(curL++);
        while (curR > R) remove_(curR--);
        ans[qq.id] = curAns;
    }

    for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i] << '\n';
    return 0;
}
