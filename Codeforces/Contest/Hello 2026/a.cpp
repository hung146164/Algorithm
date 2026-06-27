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
const ll N=5e5+5;
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
void sol()
{
    int n; cin>>n;
    vector<int> nums;
    for(int i=0; i< n; i++)
    {
        int x; cin>>x;
        nums.push_back(x);
    }
    if(nums[0]==0 && nums[nums.size()-1]==0)
    {
        cout<<"Bob"<<el;
    }
    else cout<<"Alice"<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        sol();
    }
}





