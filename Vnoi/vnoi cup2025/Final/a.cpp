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
    ll l,r,k; cin>>l>>r>>k;

    int firstr=0;
    for(int i=59 ;i>=0; i--)
    {
        if((r>>i)&1)
        {
            firstr=i;
        }
    }
    int firstl=0;
    for(int i=59 ;i>=0; i--)
    if((l>>i)&1)
    {
        firstl=i;
    }
    if(firstr==firstl && firstr<k) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';

}


