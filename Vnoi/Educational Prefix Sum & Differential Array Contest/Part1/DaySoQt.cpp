#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxll(ll a,ll b)
{
    return (a>b?a:b);
}
ll minll(ll a,ll b)
{
    return (a>b?b:a);
}
ll absll(ll a)
{
    if(a<0) return -a;
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin>>n;
    vector<ll> prefix(1,0);
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;
        prefix.push_back(prefix[i]+x);
    }

    ll currmin=LLONG_MAX/2;
    ll maxx=LLONG_MIN/2;

    for(ll i=1; i< n;i++)
    {
        currmin=minll(currmin,prefix[i]);
        maxx=maxll(maxx,prefix[n]-prefix[i]-currmin);
    }

    currmin=LLONG_MAX/2;

    for(ll i=n-1;i>=1;i--)
    {
        currmin=minll(currmin,prefix[n]-prefix[i]);
        maxx=maxll(maxx,prefix[i]-currmin);
    }
    ll ans=0;
    unordered_map<ll,ll> m;
    m.reserve(2*100000);

    for(ll i=n-1;i>=1;i--)
    {
        m[prefix[n]-prefix[i]]++;
        if(maxx==0)
        {
            ans+=m[prefix[i]];
            continue;
        }
        ans+=m[prefix[i]+maxx];
        ans+=m[prefix[i]-maxx];
    }
    cout<<maxx<<' '<<ans<<'\n';

}
