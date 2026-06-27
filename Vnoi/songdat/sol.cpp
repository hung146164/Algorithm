#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e5+3;
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

ll gt[N],ingt[N];
ll powll(ll a,ll b)
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
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i< mod; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll cal(ll n, ll m)
{
    ll ans=1;
    while(n!=0 || m!=0)
    {
        ll x=n%mod;
        ll y=m%mod;
        n/=mod;
        m/=mod;
        int val=(gt[x]*ingt[x-y]%mod)*ingt[y]%mod;
        if(y>x) val=0;
        ans= ans*val %mod;
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    ll t; cin>>t;

    while(t--)
    {
        ll n,m; cin>>n>>m;
        cout<<cal(n-m+1,m)<<'\n';
    }

}


