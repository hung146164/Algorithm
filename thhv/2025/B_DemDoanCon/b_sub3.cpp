#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+1;

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

    ll n,k; cin>>n>>k;

    vector<ll> nums(n);
    for(ll i=0; i< n;i ++)
    {
        cin>>nums[i];
    }
    ll ans=n*(n+1)/2;
    unordered_map<ll,vector<ll>> dp;
    for(ll i=0; i< n; i++)
    {
        dp[nums[i]].push_back(i);
    }
    cout<<ans<<endl;
    for(auto& i: dp)
    {
        vector<ll> curr=i.second;
        ll size=curr.size();
        if(size==1)
        {
            ans-=(n-1-curr[0])*(curr[0]+1);
            continue;
        }

        for(ll j=0; j< size; j++)
        {
            if(j==0)
            {
                ans-=(curr[j]+1)*(curr[j+1]-curr[j]);
            }
            else if(j==size-1)
            {
                ans-=(curr[j]-curr[j-1])*(n-curr[j]);
            }
            else{
                ans-=(curr[j+1]-curr[j])*(curr[j]-curr[j-1]);
            }
        }
    }
    cout<<ans<<'\n';

}

