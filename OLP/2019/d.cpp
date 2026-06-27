#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}
ll ans=0;
ll get(ll curr ,vector<vector<ll>>& g, ll parent=-1)
{
    ll maxx=0;
    for(ll i=0; i<g[curr].size(); i++)
    {
        if(g[curr][i]!=parent)
        {
            ll v=get(g[curr][i],g,curr);
            ans=max(ans,v+maxx+1);
            maxx=max(maxx,v);
        }
    }
    return maxx+1;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    ll node=n+2;

    vector<ll> parent(node+1);
    parent[node]=node;
    parent[nums[n-1]]=node;
    vector<bool> check(node+1);
    check[node]=true;
    check[nums[n-1]]=true;

    ll l=node;
    for(ll i=n-1;i>=0; i--)
    {
        if(i-1>=0 && !check[nums[i-1]])
        {
            check[nums[i-1]]=true;
            parent[nums[i-1]]=nums[i];
        }
        else{
            while(l>=0 && check[l])
            {
                l--;
            }
            check[l]=true;
            parent[l]=nums[i];
        }
    }
    vector<bool> valid(node+1,false);
    for(ll i=1; i< parent.size(); i++)
    {
        valid[parent[i]]=true;
    }
    ll hh=1;
    vector<vector<ll>> g(node+1);
    for(ll i=1; i< parent.size()-1; i++)
    {
        g[parent[i]].push_back(i);
        g[i].push_back(parent[i]);
    }
//    for(ll i=1; i< valid.size(); i++)
//    {
//        if(!valid[i])
//        {
//            ans=max(ans,get(i,g)-1);
//        }
//    }
//    cout<<hh<<'\n';
//    for(ll i=0; i< parent.size(); i++) cout<<parent[i]<<'\n';
//    cout<<endl;

    get(node,g);
    cout<<ans-1<<'\n';
}


