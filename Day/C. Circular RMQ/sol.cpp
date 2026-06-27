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
const ll N=2e5+5;
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
ll nums[N];
ll tree[N*4];
ll lazy[N*4];
void push(ll curr, ll l, ll r)
{
    if (lazy[curr] != 0)
    {
        tree[curr] += lazy[curr];
        if (l != r)
        {
            lazy[curr << 1] += lazy[curr];
            lazy[curr << 1 | 1] += lazy[curr];
        }
        lazy[curr] = 0;
    }
}
void add(ll curr,ll l,ll r,ll x,ll y,ll val)
{
    push(curr,l,r);
    if(r<x || l>y) return;
    if(x<=l && r<=y)
    {
        lazy[curr]+=val;
        push(curr,l,r);
        return;
    }

    ll m=(l+r)>>1;
    add(curr<<1,l,m,x,y,val);
    add(curr<<1|1,m+1,r,x,y,val);
    tree[curr]=min(tree[curr<<1],tree[curr<<1|1]);
}
ll query(ll curr,ll l,ll r,ll x,ll y)
{
    push(curr,l,r);
    if(r<x || l> y) return INT_MAX;
    if(x<=l && r<=y)
    {
        return tree[curr];
    }
    ll m=(l+r)>>1;
    return min(query(curr<<1,l,m,x,y),query(curr<<1|1,m+1,r,x,y));
}
void build(ll curr,ll l, ll r)
{
    if(l==r)
    {
        tree[curr]=nums[l];
        return;
    }
    ll m=(l+r)>>1;
    build(curr<<1,l,m);
    build(curr<<1|1,m+1,r);
    tree[curr]=min(tree[curr<<1],tree[curr<<1|1]);
}
void solve()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; i++)
    {
        cin>>nums[i];
    }
    build(1,1,n);
    ll q;
    cin>>q;
    string s;
    getline(cin, s);
    while(q--)
    {
        getline(cin, s);
        stringstream ss(s);
        vector<ll> c;
        ll val;
        while (ss >> val) c.push_back(val);

        ll x = c[0] + 1, y = c[1] + 1;

        if (c.size() == 2)
        {
            if (x <= y)
            {
                cout<<query(1, 1, n, x, y)<<el;
            }
            else
            {
                cout<<min(query(1, 1, n, x, n), query(1, 1, n, 1, y))<<el;
            }
        }
        else
        {
            ll v = c[2];
            if (x <= y)
            {
                add(1, 1, n, x, y, v);
            }
            else
            {

                add(1, 1, n, x, n, v);
                add(1, 1, n, 1, y, v);
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    t=1;
    while(t--)
    {
        solve();
    }
}










