#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=987654321;
const ll N=1e5+1;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n ;cin>>n;
    if(n==3) {cout<<1<<'\n'; return 0;}
    ll a=n;
    ll b=n-3;
    if(a%2==0)
    {
        a/=2;
    }
    else if(b%2==0) b/=2;
    a%=mod;
    b%=mod;

    vector<ll> cc;
    for(ll i=0; i<=3; i++) cc.push_back(n-i);
    vector<ll> mm=cc;
    vector<ll> h(2);
    for(ll i=0; i< cc.size(); i++)
    {
        while(cc[i]%2==0)
        {
            h[0]++;
            cc[i]/=2;
        }
        while(cc[i]%3==0)
        {
            h[1]++;
            cc[i]/=3;
        }
    }
    int need2=3;
    int need3=1;
    for(int i=0; i< mm.size(); i++)
    {
        while(need2 >0 && mm[i]%2==0)
        {
            mm[i]/=2; need2--;
        }
        while(need3>0 && mm[i]%3==0)
        {
            need3--;mm[i]/=3;
        }
        mm[i]%=mod;
    }

    ll ans=(( (a*b %mod + (((mm[0]*mm[1]%mod)*mm[2]%mod)*mm[3]%mod))%mod)%mod+1)%mod ;
    cout<<ans<<'\n';

}


