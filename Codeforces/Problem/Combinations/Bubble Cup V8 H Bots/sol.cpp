#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=2e6+5;

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
ll gt[N];
ll ingt[N];
ll powll(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        b/=2;
        a=a*a%mod;
    }
    return ans;
}
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i< N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    ll n; cin>>n;
    ll m=n;
    cout<<(gt[n+m+2] * ingt[n+1]%mod)*ingt[n+m+2-n-1]%mod-1<<'\n';
    //(n+m+2)C(n+1)-1
}


