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
        vector<ll> p(1,0);
        string s; cin>>s;
        for(ll i=0; i< n; i++)
        {
            ll x=s[i]-'0';
            p.push_back(p[i]+x);
        }
        unordered_map<ll,ll> m;
        ll ans=0;
        for(ll i=0; i<=n; i++)
        {
            ans+=m[p[i]-i];
            m[p[i]-i]++;
        }
        cout<<ans<<'\n';
    }

}


