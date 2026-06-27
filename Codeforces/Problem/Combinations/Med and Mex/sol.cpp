#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll N=2e5+5;

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
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N; i++)
    {
        gt[i]=gt[i-1]*i%mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
int C(int n,int k)
{
    if(n<k) return 0;

    return (gt[n]*ingt[n-k]%mod)*ingt[k]%mod;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    process();
    ll t; cin>>t;
    while(t--)
    {
        ll n; cin>>n;
        if(n==1)
        {
            cout<<0<<'\n';
            continue;
        }
        cout<<0<<' ';
        for(ll x=2; x<=n-1; x++)
        {
            if(n>=(x-1)*2)
            {
                cout<<(gt[(x-1)*2]*gt[n-(x-1)*2+1]%mod)*C(n-(x)-1,x-2)%mod<<' ';
            }
            else cout<<0<<' ';
        }
        cout<<0<<'\n';
    }

}


