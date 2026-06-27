#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

struct Seg
{
    ll n;
    vector<ll> bit;
    Seg() {}
    Seg(ll& c)
    {
        process(c);
    }
    void process(ll& c)
    {
        n = c;
        bit.assign(n + 1, 0);
    }
    void add(ll& ii, ll& val)
    {
        ++ii;
        while (ii <= n)
        {
            bit[ii] += val;
            if (bit[ii] >= mod) bit[ii] -= mod;
            ii += ii & -ii;
        }
    }
    ll prefix(ll& ii)
    {
        if (ii < 0) return 0;
        ++ii;
        ll res = 0;
        while (ii > 0)
        {
            res += bit[ii];
            ii -= ii & -ii;
        }
        return (ll)(res % mod);
    }
    ll query(ll& l, ll& r)
    {
        if (r < l) return 0;
        ll res = prefix(r) - prefix(l - 1);
        if (res < 0) res += mod;
        return res;
    }
};

void sol()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    ll m = n + 1;
    vector<ll> dp(m * m, 0);
    dp[0] = 1;
    vector<Seg> col(m), row(m);
    for (ll i = 0; i < m; ++i)
    {
        col[i].process(m);
        row[i].process(m);
    }
    for (ll j = 0; j < m; ++j)
    {
        for (ll k = 0; k < m; ++k)
        {
            ll val = dp[j * m + k];
            if (val)
            {
                col[k].add(j, val);
                row[j].add(k, val);
            }
        }
    }
    for (ll ii = 0; ii < n; ++ii)
    {
        ll v = a[ii];
        vector<pair<ll,ll>> need;
        need.reserve(2 * m + 5);
        for (ll k = 0; k < m; ++k)
        {
            ll add = 0;
            if (k > v) add = col[k].query(0, v);
            else add = col[k].query(k, v);
            if (add)
            {
                ll pos = v * m + k;
                need.emplace_back(pos, add);
            }
        }
        for (ll j = 0; j < m; ++j)
        {
            ll add = 0;
            if (j > v) add = row[j].query(0, v);
            else add = row[j].query(j + 1, v);
            if (add)
            {
                ll pos = j * m + v;
                need.emplace_back(pos, add);
            }
        }
        for (auto &p : need)
        {
            ll pos = p.first;
            ll add = p.second;
            ll newval = dp[pos] + add;
            if (newval >= mod) newval -= mod;
            ll delta = add % mod;
            dp[pos] = newval;
            ll j = pos / m;
            ll k = pos % m;
            col[k].add(j, delta);
            row[j].add(k, delta);
        }
    }
    ll ans = 0;
    for (ll x : dp)
    {
        ans += x;
        if (ans >= (1LL<<62)) ans %= mod;
    }
    ans %= mod;
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) sol();
}
