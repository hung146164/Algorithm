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
const ll inf=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}


ll tree_sum[N*4];
ll tree_min[N*4];
ll nums[N];
void update(ll curr ,ll l, ll r, ll x, ll y,ll k)
{
    if(r<x || l>y) return;
    if(x<=l && r<=y)
    {
        if(tree_min[curr]<k) return;
        if(l==r)
        {
            tree_sum[curr]=tree_sum[curr]%k;
            tree_min[curr]=tree_min[curr]%k;
            return;
        }
    }
    ll m=l+(r-l)/2;
    update(curr*2+1,l,m,x,y,k);
    update(curr*2+2,m+1,r,x,y,k);
    tree_min[curr]=max(tree_min[curr*2+1],tree_min[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
void update_pos(ll curr ,ll l, ll r, ll x,ll val)
{
    if(l==r)
    {
        tree_min[curr]=val;
        tree_sum[curr]=val;
        return;
    }
    ll m=l+(r-l)/2;
    if(x<=m)
    {
        update_pos(curr*2+1,l,m,x,val);
    }
    else update_pos(curr*2+2,m+1,r,x,val);
    tree_min[curr]=min(tree_min[curr*2+1],tree_min[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
ll query(ll curr,ll l, ll r, ll x,ll y)
{
    if(r<x || l>y) return INT_MAX;
    if(x<=l && r<=y)
    {
        return tree_min[curr];
    }
    ll m=l+(r-l)/2;
    return min(query(curr*2+1,l,m,x,y),query(curr*2+2,m+1,r,x,y));
}
void build(ll curr ,ll l, ll r)
{
    if(l==r)
    {
        tree_min[curr]=nums[l];
        tree_sum[curr]=nums[l];
        return;
    }
    ll m=l+(r-l)/2;
    build(curr*2+1,l,m);
    build(curr*2+2,m+1,r);
    tree_min[curr]=min(tree_min[curr*2+1],tree_min[curr*2+2]);
    tree_sum[curr]=tree_sum[curr*2+1]+tree_sum[curr*2+2];
}
void solve()
{
    ll n,q; cin>>n>>q;
    for(ll i=0; i< n; i++)
    {
        cin>>nums[i];
    }
    build(0,0,n-1);
    while(q--)
    {
        ll a, b, c; cin>>a>>b>>c;

        if(a==1)
        {
            update_pos(0,0,n-1,b-1,c);
        }
        else{
            ll start=b-1;
            ll l=b-1, r=c-1;
            ll ans=0;
            while(l<=r)
            {
                ll m=l+(r-l)/2;
                ll val = query(0,0,n-1,start,m);
                if(val>(m-start))
                {
                    l=m+1;
                }
                else if(val==(m-start))
                {
                    ans=1;
                    break;
                }
                else
                    {
                    r=m-1;
                }
            }
            cout<<ans<<el;

        }
    }
    //cout<<query(0,0,n-1,0,2)<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}







