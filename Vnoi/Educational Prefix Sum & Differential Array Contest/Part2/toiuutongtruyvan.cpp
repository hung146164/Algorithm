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
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; cin>>n>>q;
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }
    vector<ll> prefix(n+1);
    for(ll i=0; i< q; i++)
    {
        ll a,b; cin>>a>>b;
        a--;b--;
        prefix[a]++;
        prefix[b+1]--;
    }
    vector<ll> hh;
    ll curr=0;
    for(ll i=0; i<n; i++)
    {
        curr+=prefix[i];
        hh.push_back(curr);
    }
    sort(hh.begin(),hh.end(),greater<ll>());
    sort(nums.begin(),nums.end(),greater<ll>());
    ll ans=0;
    for(ll i=0; i< nums.size(); i++)
    {
        ans+=nums[i]*hh[i];
    }
    cout<<ans<<'\n';
}


