#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

struct Seg {
    int n;
    vector<pair<long long, long long>> tree;
    vector<long long> lazy;

    Seg(int _n) {
        n = _n;
        tree.assign(4 * n, {0LL, 0LL});
        lazy.assign(4 * n, 0LL);
    }
    void push(int curr, int l, int r) {
        if (lazy[curr] != 0) {
            long long addMoney = (lazy[curr] * (tree[curr].first % MOD)) % MOD;
            tree[curr].second = (tree[curr].second + addMoney) % MOD;
            if (l < r) {
                lazy[curr*2 + 1] = (lazy[curr*2 + 1] + lazy[curr]) % MOD;
                lazy[curr*2 + 2] = (lazy[curr*2 + 2] + lazy[curr]) % MOD;
            }
            lazy[curr] = 0;
        }
    }
    void add(int idx, long long val, int curr = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        push(curr, l, r);

        if (l == r) {
            tree[curr].first = (tree[curr].first + val) % MOD;
            return;
        }

        int m = l+(r-l)/2;
        if (idx <= m) {
            add(idx, val, curr*2 + 1, l, m);
        } else {
            add(idx, val, curr*2 + 2, m + 1, r);
        }
        tree[curr].first = (tree[curr*2 + 1].first + tree[curr*2 + 2].first) % MOD;
        tree[curr].second = (tree[curr*2 + 1].second + tree[curr*2 + 2].second) % MOD;
    }

    void tang(long long v, int curr = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        lazy[curr] = (lazy[curr] + v) % MOD;
    }

    long long rut(int idx, int curr = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        push(curr, l, r);
        if (l == r) {
            long long ans = tree[curr].second % MOD;
            tree[curr].second = 0;
            return ans;
        }
        int m = l+(r-l)/2;
        long long res;
        if (idx <= m) {
            res = rut(idx, curr*2 + 1, l, m);
            push(curr*2 + 2, m+1, r);
        } else {
            res = rut(idx, curr*2 + 2, m + 1, r);
            push(curr*2 + 1, l, m);
        }
        tree[curr].first = ( (tree[curr*2 + 1].first % MOD) + (tree[curr*2 + 2].first % MOD) ) % MOD;
        tree[curr].second = ( (tree[curr*2 + 1].second % MOD) + (tree[curr*2 + 2].second % MOD) ) % MOD;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    Seg seg(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            long long x;
            cin >> p >> x;
            --p;
            seg.add(p, x);
        }
        else if (type == 2) {
            long long v;
            cin >> v;
            seg.tang(v);
        }
        else {
            int p;
            cin >> p;
            --p;
            long long ans = seg.rut(p) % MOD;
            if (ans < 0) ans += MOD;
            cout << ans << "\n";
        }
    }
    return 0;
}
