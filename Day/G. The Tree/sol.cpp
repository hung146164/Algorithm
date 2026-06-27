/*
    Author: HungForree
    Link:
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<int> g[N];

int parent[N], heavy[N];
int n, q;

int in[N], out[N], depth[N], head[N];
int id=1;

int dfs1(int curr, int p=0)
{
    parent[curr] = p;
    int child_heavy_idx = -1;
    int child_count = 1;
    int child_max = 0;
    for(int i=0; i< g[curr].size(); i++)
    {
        int v=g[curr][i];
        if(v == p) continue;
        int cnt = dfs1(v, curr);
        if(cnt > child_max)
        {
            child_max = cnt;
            child_heavy_idx=i;
        }
        child_count += cnt;
    }
    heavy[curr] = g[curr][child_heavy_idx];

    if(child_heavy_idx != -1) {
        swap(g[curr][0],g[curr][child_heavy_idx]);
    }
    return child_count;
}

void dfs2(int curr, int h, int d=1)
{
    in[curr] = id++;
    depth[curr] = d;
    head[curr] = h;

    for(int i = 0; i < g[curr].size(); i++)
    {
        if(g[curr][i] == parent[curr]) continue;
        if(i == 0 ) dfs2(g[curr][i], h, d+1);
        else dfs2(g[curr][i], g[curr][i], d+1);
    }
    out[curr]=id-1;
}

struct Node {
    ll sum, suf;
} tree[N*4];

bool lazy[N*4];

Node combine(Node L, Node R) {
    return {L.sum + R.sum, max(R.suf, R.sum + L.suf)};
}

void build(int curr, int l, int r) {
    if (l == r) {
        tree[curr] = {-1, -1};
        return;
    }
    int m = l + (r - l) / 2;
    build(curr*2, l, m);
    build(curr*2+1, m+1, r);
    tree[curr] = combine(tree[curr*2], tree[curr*2+1]);
}

void push(int curr, int l, int r) {
    if (!lazy[curr]) return;
    int m = l + (r - l) / 2;

    tree[curr*2].sum = -(m - l + 1);
    tree[curr*2].suf = -1;
    lazy[curr*2] = true;

    tree[curr*2+1].sum = -(r - m);
    tree[curr*2+1].suf = -1;
    lazy[curr*2+1] = true;

    lazy[curr] = false;
}

void update_add(int curr, int l, int r, int x, ll val) {
    if (l == r) {
        tree[curr].sum += val;
        tree[curr].suf += val;
        return;
    }
    push(curr, l, r);
    int m = l + (r - l) / 2;
    if (x <= m) update_add(curr*2, l, m, x, val);
    else update_add(curr*2+1, m+1, r, x, val);
    tree[curr] = combine(tree[curr*2], tree[curr*2+1]);
}

void update_set(int curr, int l, int r, int x, int y) {
    if (r < x || l > y) return;
    if (x <= l && r <= y) {
        tree[curr].sum = -(r - l + 1);
        tree[curr].suf = -1;
        lazy[curr] = true;
        return;
    }
    push(curr, l, r);
    int m = l + (r - l) / 2;
    update_set(curr*2, l, m, x, y);
    update_set(curr*2+1, m+1, r, x, y);
    tree[curr] = combine(tree[curr*2], tree[curr*2+1]);
}

Node query(int curr, int l, int r, int x, int y) {
    if (r < x || l > y) return {0, -inf};
    if (x <= l && r <= y) return tree[curr];
    push(curr, l, r);
    int m = l + (r - l) / 2;
    return combine(query(curr*2, l, m, x, y), query(curr*2+1, m+1, r, x, y));
}

ll pathquery(int v) {
    Node ans = {0, -inf};
    while (head[v] != head[1]) {
        Node chain_node = query(1, 1, n, in[head[v]], in[v]);
        ans = combine(chain_node, ans);
        v = parent[head[v]];
    }
    Node chain_node = query(1, 1, n, in[1], in[v]);
    ans = combine(chain_node, ans);
    return ans.suf;
}

void solve()
{
    cin >> n >> q;
    for(int i = 2; i <= n; i++)
    {
        int p; cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);

    while(q--)
    {
        int type, v; cin >> type >> v;
        if(type == 1)
        {
            update_add(1, 1, n, in[v], 1);
        }
        else if(type == 2)
        {
            ll S = (v == 1) ? 0 : pathquery(parent[v]);
            ll M = max(0LL, S);

            update_set(1, 1, n, in[v], out[v]);
            if (M > 0) {
                update_add(1, 1, n, in[v], -M);
            }
        }
        else
        {
            if (pathquery(v) >= 0) cout << "black" << el;
            else cout << "white" << el;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int t = 1;
    while(t--)
    {
        solve();
    }
}
