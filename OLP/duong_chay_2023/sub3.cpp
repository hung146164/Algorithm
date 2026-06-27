#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const ll INV6 = (MOD + 1) / 6; // nghịch đảo của 6 mod MOD

int n;
ll T;
vector<ll> h;
vector<vector<int>> adj;

ll modMul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }
ll modAdd(ll a, ll b) { a += b; if (a >= MOD) a -= MOD; return a; }
ll modSub(ll a, ll b) { a -= b; if (a < 0) a += MOD; return a; }

ll C3(ll x) {
    if (x < 3) return 0;
    ll res = x % MOD;
    res = modMul(res, (x-1) % MOD);
    res = modMul(res, (x-2) % MOD);
    res = modMul(res, INV6);
    return res;
}

// DFS tính size subtree
int dfs_size(int u, int p, vector<int> &vis, vector<int> &allowed, vector<int> &sz) {
    vis[u] = 1;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p || !allowed[v]) continue;
        if (!vis[v]) {
            sz[u] += dfs_size(v, u, vis, allowed, sz);
        }
    }
    return sz[u];
}

// DFS tính đóng góp cạnh
ll dfs_contrib(int u, int p, int compSize, vector<int> &allowed, vector<int> &sz) {
    ll ans = 0;
    for (int v : adj[u]) {
        if (v == p || !allowed[v]) continue;
        int s = sz[v];
        ll val = modSub(C3(compSize), modAdd(C3(s), C3(compSize - s)));
        val = modMul(val, 2);
        ans = modAdd(ans, val);
        ans = modAdd(ans, dfs_contrib(v, u, compSize, allowed, sz));
    }
    return ans;
}

ll solveAllowed(ll limit) {
    vector<int> allowed(n+1, 0);
    for (int i=1; i<=n; i++) if (h[i] <= limit) allowed[i] = 1;

    vector<int> vis(n+1,0), sz(n+1,0);
    ll ans = 0;

    for (int i=1;i<=n;i++) {
        if (allowed[i] && !vis[i]) {
            // tìm component chứa i
            int compSize = dfs_size(i, -1, vis, allowed, sz);
            // tính đóng góp cạnh trong component
            ans = modAdd(ans, dfs_contrib(i, -1, compSize, allowed, sz));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> T;
    h.assign(n+1, 0);
    for (int i=1;i<=n;i++) cin >> h[i];
    adj.assign(n+1, {});
    for (int i=0;i<n-1;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll res = modSub(solveAllowed(T), solveAllowed(T-1));
    cout << res << "\n";
}

