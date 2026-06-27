/*
    Author: HungForree
    Link: https://codeforces.com/contest/414/problem/D
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
ll depth[N];
ll prefix[N+1];
vector<vector<ll>> g(N);
ll depth_max=0;
void dfs(ll curr,ll p=-1,ll d=0)
{
    if(d!=0) depth[d]++;
    depth_max=max(depth_max,d);
    for(ll i=0; i< g[curr].size(); i++)
    {
        if(g[curr][i]==p) continue;
        dfs(g[curr][i],curr,d+1);
    }
}
void solve()
{
    ll n,k,p; cin>>n>>k>>p;
    for(ll i=0; i< n-1;i++)
    {
        ll a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
//    for(ll i=0; i< 10 ;i++)
//    {
//        cout<<depth[i]<<' ';
//    }
//    cout<<el;
    reverse(depth,depth+depth_max+1);
//    for(ll i=0; i< 10 ;i++)
//    {
//        cout<<depth[i]<<' ';
//    }
//    cout<<el;
    for(ll i=1;i<=N;i++)
    {
        prefix[i]=depth[i-1]+prefix[i-1];
    }
//    for(ll i=0; i<10;i++)
//    {
//        cout<<prefix[i]<<' ';
//    }
//    cout<<el;

    ll tien=p,lo=0;
    ll ans=0;

    for(ll r=0,l=0; r<=depth_max;r++)
    {
        tien-=(r-l)*depth[r];
        lo+=depth[r];
        //cout<<l<<' '<<r<<' '<<tien<<' '<<lo<<el;
        if(tien<0)
        {
            ans=max(ans,min(k,lo-depth[r]+(tien+(r-l)*depth[r])/(r-l)));
        }
        while(tien<0)
        {
            lo-=depth[l];
            tien+=prefix[r+1]-prefix[l+1];
            l++;
        }
        ans=max(ans,min(lo,k));
    }
    cout<<ans<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}









