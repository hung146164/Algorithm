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

    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll> nums;
        ll total=0;
        for(ll i=0; i< n; i++)
        {
            ll x; cin>>x;
            nums.push_back(x);
            total+=x;
        }
        ll j=0;
        sort(nums.begin(),nums.end());
        while(j<nums.size() && nums[j]==0)
        {
            j++;
        }
        ll can=n-j;
        while(total-can<n-1)
        {
            can--;
        }
        cout<<can<<'\n';
    }
}


