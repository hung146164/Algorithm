/*
    Author: HungForree

*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;
#define el '\n'

const int N = 5e5 + 5;

int n, q;
vector<int> g[N];

int parent[N], depth[N], heavy[N], sz[N];
int head[N], pos[N], cur_pos = 1;

int st_fill[4 * N];
int st_empty[4 * N];

void dfs1(int u, int p = 0, int d = 1) {
    parent[u] = p;
    depth[u] = d;
    sz[u] = 1;
    heavy[u] = 0;
    int max_sz = -1;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (sz[v] > max_sz) {
            max_sz = sz[v];
            heavy[u] = v;
        }
    }
}

void dfs2(int u, int head_node) {
    head[u] = head_node;
    pos[u] = cur_pos++;

    if (heavy[u]) {
        dfs2(heavy[u], head_node);
    }

    for (int v : g[u]) {
        if (v != parent[u] && v != heavy[u]) {
            dfs2(v, v);
        }
    }
}

void update(int* st, int id, int l, int r, int p, int val) {
    if (l == r) {
        st[id] = val;
        return;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(st, id << 1, l, m, p, val);
    else update(st, id << 1 | 1, m + 1, r, p, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int get_max(int* st, int id, int l, int r, int x, int y) {
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) return st[id];
    int m = (l + r) >> 1;
    return max(get_max(st, id << 1, l, m, x, y),
               get_max(st, id << 1 | 1, m + 1, r, x, y));
}

// hld
int get_path_max_fill(int u) {
    int ans = 0;
    while (u) {
        ans = max(ans, get_max(st_fill, 1, 1, n, pos[head[u]], pos[u]));
        u = parent[head[u]];
    }
    return ans;
}


int get_subtree_max_empty(int u) {

    return get_max(st_empty, 1, 1, n, pos[u], pos[u] + sz[u] - 1);
}

void solve() {
    if (!(cin >> n)) return;

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1);
    dfs2(1, 1);

    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {

            update(st_fill, 1, 1, n, pos[v], i);
        }
        else if (type == 2) {

            update(st_empty, 1, 1, n, pos[v], i);
        }
        else {

            int last_fill = get_path_max_fill(v);
            int last_empty = get_subtree_max_empty(v);

            if (last_fill > last_empty) cout << 1 << el;
            else cout << 0 << el;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
