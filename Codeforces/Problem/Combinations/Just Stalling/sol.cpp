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
signed main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<ll> nums(n);
    vector<ll> ch;
    for(ll i=0; i< n; i++)
        cin>>nums[i];
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        ch.push_back(x);
    }
    sort(nums.begin(),nums.end(),greater<ll>());
    sort(ch.begin(),ch.end(),greater<ll>());
    ch.push_back(0);
    ll cnt=0;
    ll l=0;
    vector<ll> hh;
//    for(auto i: nums) cout<<i<<' ';
//    cout<<'\n';
//    for(auto i: ch) cout<<i<<' ';
//    cout<<'\n';
    for(ll i=0; i< ch.size(); i++)
    {

        while(l<nums.size() && nums[l]>ch[i])
        {
            hh.push_back(cnt);
            l++;
        }
        cnt++;
    }
    ll ans=1;

    for(ll i=0; i< hh.size(); i++)
    {
        //cout<<hh[i]<<' ';
        ans*=hh[i]-i;
    }
    //cout<<'\n';
    cout<<ans<<'\n';

}


