/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/61/E
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=1e6+5;
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

struct ST
{
    public:
    vector<ll> tree;
    ST(ll n)
    {
        tree.resize(n*4);
    }
    void add(ll curr, ll l, ll r, ll x, ll val)
    {
        if(l==r)
        {
            tree[curr]+=val;
            return;
        }
        ll m=l+(r-l)/2;
        if(x<=m)
        {
            add(curr*2,l,m,x,val);
        }
        else
        {
            add(curr*2+1,m+1,r,x,val);
        }
        tree[curr]=tree[curr*2]+tree[curr*2+1];
    }
    ll query(ll curr ,ll l, ll r, ll x, ll y)
    {
        if(x<=l && r<=y) return tree[curr];
        if(r<x || l>y) return 0;
        ll m=l+(r-l)/2;
        return query(curr*2,l,m,x,y)+query(curr*2+1,m+1,r,x,y);
    }
};
void solve()
{
    //cout<<"OK"<<endl;
    ll n; cin>>n;
    vector<ll> nums(n+1);
    for(ll i=1; i<=n; i++) cin>>nums[i];
    vector<ll> clone=nums;
    sort(clone.begin(), clone.end());
    clone.erase(unique(clone.begin(),clone.end()),clone.end());

    for(ll i=1; i<=n; i++)
    {
        nums[i]=lower_bound(clone.begin(),clone.end(),nums[i])-clone.begin()+1;
    }

    ST t1(N),t2(N);
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        t1.add(1,1,N,nums[i],1);
        //cout<<t1.query(1,1,N,nums[i]+1,N)<<el;
        t2.add(1,1,N,nums[i],t1.query(1,1,N,nums[i]+1,N));
        ans+=t2.query(1,1,N,nums[i]+1,N);
    }
    cout<<ans<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t=1;
    while(t--)
    {
        solve();
    }
}










