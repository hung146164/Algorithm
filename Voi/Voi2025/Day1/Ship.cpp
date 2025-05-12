#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Seg {
public:
    vector<ll> nums;
    vector<ll> tree;

    Seg(vector<ll>& num) {
        nums = num;
        tree.resize(nums.size() * 4);
        build(0, 0, nums.size() - 1);
    }

    void build(ll curr, ll l, ll r) {
        if (l == r) {
            tree[curr] = nums[l];
            return;
        }
        ll m = (l + r) / 2;
        build(curr * 2 + 1, l, m);
        build(curr * 2 + 2, m + 1, r);
        tree[curr] = max(tree[curr * 2 + 1], tree[curr * 2 + 2]);
    }

    ll query(ll curr, ll l, ll r, ll x, ll y) {
        if (r < x || l > y) return 0;
        if (x <= l && r <= y) return tree[curr];
        ll m = (l + r) / 2;
        return max(query(curr * 2 + 1, l, m, x, y), query(curr * 2 + 2, m + 1, r, x, y));
    }
};

// Memoization mảng để tránh tính lại
ll sol(ll curr, vector<vector<pair<ll, bool>>>& as, Seg& seg, ll& n, vector<ll>& dp) {
    if (dp[curr] != -1) return dp[curr];
    ll ans = 0;

    for (ll i = 0; i < as[curr].size(); i++) {
        if (!as[curr][i].second) {
            as[curr][i].second = true;
            ll u = curr;
            ll v = as[curr][i].first;
            if (u > v) swap(u, v);
            ans = max(ans, sol(v, as, seg, n, dp) + seg.query(0, 0, n - 1, u, v));
            as[curr][i].second = false;
        }
    }

    return dp[curr] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SHIP.INP","r",stdin);
    freopen("SHIP.OUT","w", stdout);
    ll n;
    cin >> n;

    vector<ll> val(n);
    for (ll i = 0; i < n; i++) {
        cin >> val[i];
    }

    Seg seg(val);

    // Đọc đồ thị gốc (giữ lại nếu bạn muốn dùng sau này)
    vector<vector<pair<ll, bool>>> graph(n);
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back({y, false});
    }

    ll k;
    cin >> k;
    vector<vector<pair<ll, bool>>> asign(n);
    for (ll i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        asign[x].push_back({y, false});
    }

    // Memoization
    vector<ll> dp(n, -1);

    cout << sol(0, asign, seg, n, dp) << endl;
    return 0;
}
