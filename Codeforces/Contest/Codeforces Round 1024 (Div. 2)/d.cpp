#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct SegTree {
    ll n;
    vector<ll> st;
    SegTree(ll _n) : n(_n), st(4*_n, 0) {}
    void update(ll p, ll tl, ll tr, ll i) {
        if (tl == tr) {
            st[p] ^= 1;
            return;
        }
        ll tm = (tl + tr) / 2;
        if (i <= tm) update(p*2,   tl,    tm, i);
        else         update(p*2+1, tm+1, tr, i);
        st[p] = st[p*2] ^ st[p*2+1];
    }
    ll query(ll p, ll tl, ll tr, ll l, ll r) {
        if (l > r) return 0;
        if (l <= tl && tr <= r) return st[p];
        ll tm = (tl + tr) / 2, res = 0;
        if (l <= tm) res ^= query(p*2,   tl,    tm, l, r);
        if (r  > tm) res ^= query(p*2+1, tm+1, tr, l, r);
        return res;
    }
};

ll cp(const vector<ll>& v_in) {
    vector<ll> v = v_in;
    ll m = v.size();
    vector<ll> xs = v;
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (ll &x : v)
        x = ll(lower_bound(xs.begin(), xs.end(), x) - xs.begin()) + 1;
    SegTree seg(xs.size());
    ll parity = 0;
    for (ll i = m - 1; i >= 0; --i) {
        if (v[i] > 1)
            parity ^= seg.query(1, 1, seg.n, 1, v[i] - 1);
        seg.update(1, 1, seg.n, v[i]);
    }
    return parity;
}

vector<ll> dfs(ll n, const vector<ll>& sortchan, const vector<ll>& sortle,
                        bool flip_chan, bool flip_le) {
    vector<ll> res(n);
    vector<ll> c = sortchan;
    vector<ll> l = sortle;
    if (flip_chan && c.size() >= 2) swap(c[0], c[1]);
    if (flip_le   && l.size() >= 2) swap(l[0], l[1]);
    for (ll i = 0, ic = 0, il = 0; i < n; ++i) {
        if (i % 2 == 0) res[i] = c[ic++];
        else            res[i] = l[il++];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];

        vector<ll> chan, le;
        for (ll i = 0; i < n; ++i) {
            if (i % 2 == 0) chan.push_back(a[i]);
            else            le.push_back(a[i]);
        }
        vector<ll> sortchan = chan;
        vector<ll> sortle   = le;
        sort(sortchan.begin(), sortchan.end());
        sort(sortle.begin(),   sortle.end());

        ll p_chan = cp(chan);
        ll p_le   = cp(le);

        vector<ll> ans;
        if (p_chan == p_le) {
            ans = dfs(n, sortchan, sortle, false, false);
        } else {
            auto cand1 = dfs(n, sortchan, sortle, true,  false);
            auto cand2 = dfs(n, sortchan, sortle, false, true);
            ans = min(cand1, cand2);
        }

        for (ll x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}
