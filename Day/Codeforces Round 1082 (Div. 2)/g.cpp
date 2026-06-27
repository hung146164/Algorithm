
#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
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

ll tree_sum[N*4];
ll tree_max[N*4];
ll nums[N];
void update(ll curr ,ll l, ll r, ll x, ll y,ll k)
{
    if(r<x || l>y) return;
    if(x<=l && r<=y)
    {
        if(tree_max[curr]<k) return;
        if(l==r)
        {
            tree_sum[curr]=tree_sum[curr]%k;
            tree_max[curr]=tree_max[curr]%k;
            return;
        }
    }
    ll m=l+(r-l)/2;
    update(curr*2+1,l,m,x,y,k);
    update(curr*2+2,m+1,r,x,y,k);
    tree_max[curr]=max(tree_max[curr*2+1],tree_max[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
void update_pos(ll curr ,ll l, ll r, ll x,ll val)
{
    if(l==r)
    {
        tree_max[curr]=val;
        tree_sum[curr]=val;
        return;
    }
    ll m=l+(r-l)/2;
    if(x<=m)
    {
        update_pos(curr*2+1,l,m,x,val);
    }
    else update_pos(curr*2+2,m+1,r,x,val);
    tree_max[curr]=max(tree_max[curr*2+1],tree_max[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
ll query(ll curr,ll l, ll r, ll x,ll y)
{
    if(r<x || l>y) return 0;
    if(x<=l && r<=y)
    {
        return tree_sum[curr];
    }
    ll m=l+(r-l)/2;
    return query(curr*2+1,l,m,x,y)+query(curr*2+2,m+1,r,x,y);
}
void build(ll curr ,ll l, ll r)
{
    if(l==r)
    {
        tree_max[curr]=nums[l];
        tree_sum[curr]=nums[l];
        return;
    }
    ll m=l+(r-l)/2;
    build(curr*2+1,l,m);
    build(curr*2+2,m+1,r);
    tree_max[curr]=max(tree_max[curr*2+1],tree_max[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> rf(n + 1, 0);
    vector<int> cf(n + 1, 0);
    vector<int> lc(n + 2, 0);

    ll colScore = 0;
    ll rowScore = 0;

    for (int i = 0; i < q; ++i) {
        int r, c;
        cin >> r >> c;

        int nxt = rf[r] + 1;
        rowScore += 2LL * lc[nxt] + 1;
        lc[nxt]++;
        rf[r]++;

        colScore += 2LL * cf[c] + 1;
        cf[c]++;

        if (colScore == rowScore) {
            cout << "YES" << el;
        } else {
            cout << "NO" << el;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);

    int t;
    if (cin >> t) {
        while (t--)
        {
            solve();
        }
    }

    return 0;
}
