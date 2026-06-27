#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int N=1e5+5;
const int mod=998244353;
ll powll(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        b/=2;
        a=a*a%mod;
    }
    return ans;
}
void solve()
{
    ll n,m,r,c;
    cin>>n>>m>>r>>c;
    //m*(r-1)+(c-1)*(n-r+1)
    cout<<powll(2,m*(r-1))*powll(2,(c-1)*(n-r+1))%mod<<'\n';

}

signed main()
{
    int t; cin>>t;
    while(t--)
    {
    solve();

    }
}









