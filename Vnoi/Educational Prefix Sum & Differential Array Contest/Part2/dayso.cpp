#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll minll(ll a,ll b)
{
    return (a<b?a:b);
}
int main()
{
    ll n; cin>>n;
    vector<ll> p(n+1);
    vector<ll> minL(n+1),minR(n+1);
    for(ll i=1; i<= n; i++)
    {
        ll x; cin>>x;
        p[i]=x+p[i-1];
        minL[i]=minll(minL[i-1],p[i]);
    }
    minR[n]=p[n];
    for(ll i=n-1;i>=0; i--)
    {
        minR[i]=minll(minR[i+1],p[i]);
    }
    ll ans=0;
    for(ll j=0; j<n; j++)
    {
        if(minR[j+1]-p[j]>0 && p[n]-p[j]+minL[j]>0)
        {
            ans++;
        }
    }
    cout<<ans<<'\n';
}
