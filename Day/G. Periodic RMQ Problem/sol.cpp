/*
    Author: HungForree
    Link: https://codeforces.com/contest/803/problem/G
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int st[20][N];
int nums[N];
int n, k;

void build()
{
    for(int i=0;i<n; i++)
    {
        st[0][i]=nums[i];
    }
    for(int j=1;j<20; j++)
    {
        for(int i=0; i+(1<<j)<=n; i++)
        {
            st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
        }
    }
}

int getminlr(int l, int r)
{
    int len = r - l + 1;
    if (len >= n)
    {
        int kc = __lg(n);
        return min(st[kc][0], st[kc][n - (1 << kc)]);
    }

    int u = l % n;
    int v = r % n;

    if (u <= v)
    {
        int kc = __lg(v - u + 1);
        return min(st[kc][u], st[kc][v - (1 << kc) + 1]);
    }

    int kc1 = __lg(n - u);
    int re1 = min(st[kc1][u], st[kc1][n - (1 << kc1)]);

    int kc2 = __lg(v + 1);
    int re2 = min(st[kc2][0], st[kc2][v - (1 << kc2) + 1]);

    return min(re1, re2);
}

struct node
{
    public:
    int min_val;
    int lazy;
    node *left, *right;

    node(int l, int r)
    {
        lazy = -1;
        left = right = nullptr;
        min_val = getminlr(l, r);
    }
};

void push(node* cur, int l, int r) {
    if (cur->lazy != -1) {
        int mid = l + (r - l) / 2;

        if (!cur->left) cur->left = new node(l, mid);
        cur->left->min_val = cur->lazy;
        cur->left->lazy = cur->lazy;

        if (!cur->right) cur->right = new node(mid + 1, r);
        cur->right->min_val = cur->lazy;
        cur->right->lazy = cur->lazy;

        cur->lazy = -1;
    }
}

void upd(node* cur, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (u <= l && r <= v) {
        cur->min_val = val;
        cur->lazy = val;
        return;
    }
    push(cur, l, r);
    int mid = l + (r - l) / 2;

    if (!cur->left) cur->left = new node(l, mid);
    upd(cur->left, l, mid, u, v, val);

    if (!cur->right) cur->right = new node(mid + 1, r);
    upd(cur->right, mid + 1, r, u, v, val);

    cur->min_val = min(cur->left->min_val, cur->right->min_val);
}

int get(node* cur, int l, int r, int u, int v) {
    if (l > v || r < u) return 2e9 + 7;

    if (cur == nullptr) {
        return getminlr(max(l, u), min(r, v));
    }

    if (u <= l && r <= v) return cur->min_val;

    push(cur, l, r);
    int mid = l + (r - l) / 2;

    return min(get(cur->left, l, mid, u, v),
               get(cur->right, mid + 1, r, u, v));
}

void solve()
{
    cin>>n>>k;
    for(int i=0; i< n; i++) cin>>nums[i];

    build();

    int q; cin >> q;
    node* root = new node(0, n * k - 1);

    while(q--) {
        int type;
        int l, r, x;
        cin >> type >> l >> r;
        l--; r--;

        if (type == 1) {
            cin >> x;
            upd(root, 0, n * k - 1, l, r, x);
        } else {
            cout << get(root, 0, n * k - 1, l, r) << el;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
