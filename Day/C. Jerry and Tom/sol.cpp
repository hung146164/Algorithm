/*

    Author: HungForree

    Link: https://codeforces.com/contest/2187/problem/C

*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=2e5+5;

int max_to[N];
vector<int> adj[N];
ll dep[N];
ll sz[N];


ll calc_lca_sum(int u) {
    ll current_ans = 0;
    sz[u] = 1;


    ll pairs_rooted_at_u = 0;

    ll sum_sq_sz_children = 0;

    for (int v : adj[u]) {
        dep[v] = dep[u] + 1;
        current_ans += calc_lca_sum(v);
        sz[u] += sz[v];


        sum_sq_sz_children += (ll)sz[v] * (sz[v] - 1) / 2;
    }


    ll pairs_with_lca_u = (ll)sz[u] * (sz[u] - 1) / 2 - sum_sq_sz_children;


    current_ans += pairs_with_lca_u * dep[u];

    return current_ans;
}


map<int, int> dfs_solve_equal(int u, ll &ans_part3) {
    map<int, int> mp;
    mp[dep[u]] = 1;

    for (int v : adj[u]) {
        map<int, int> child_mp = dfs_solve_equal(v, ans_part3);


        if (mp.size() < child_mp.size()) {
            swap(mp, child_mp);
        }


        for (auto [d, cnt] : child_mp) {

            if (mp.count(d)) {

                ans_part3 += (ll)cnt * mp[d] * (d - dep[u]);
            }
        }

        for (auto [d, cnt] : child_mp) {
            mp[d] += cnt;
        }
    }
    return mp;
}

void solve() {
    int n, m;
    cin >> n >> m;


    for(int i=1; i<=n; i++) {
        adj[i].clear();
        max_to[i] = i + 1;
    }


    for(int i=0; i<m; i++) {
        int u, v; cin >> u >> v;

        max_to[u] = max(max_to[u], v);
    }


    for(int u=1; u<n; u++) {
        int parent = max_to[u];
        adj[parent].push_back(u);
    }


    dep[n] = 0;
    ll sum_lca = calc_lca_sum(n);


    vector<ll> depths;
    for(int i=1; i<=n; i++) depths.push_back(dep[i]);
    sort(depths.begin(), depths.end());

    ll sum_min = 0;
    for(int i=0; i<n; i++) {

        sum_min += depths[i] * (n - 1 - i);
    }


    ll sum_equal_correction = 0;
    dfs_solve_equal(n, sum_equal_correction);

    cout << sum_min - sum_lca + sum_equal_correction << el;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
