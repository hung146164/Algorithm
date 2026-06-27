#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+5;
const int mod=1e9+7;
ll n,d;
ll prefix[N];
ll query(ll a, ll b)
{
    b%=n;
    a=(a+n)%n;
    if(a<=b)
    {
        return prefix[b]-(a>0?prefix[a-1]:0);
    }
    else{
        return prefix[b]+prefix[n-1]-prefix[a-1];
    }

}
void solve()
{
    cin>>n>>d;
    vector<ll> a(n);
    for(ll i=0;i<n; i++)
    {
        cin>>a[i];
    }
    prefix[0]=a[0];
    for(ll i=1;i<n; i++)
    {
        prefix[i]=prefix[i-1]+a[i];
    }
    ll ans=0;
    for(ll i=0; i< n; i++)
    {
        ll sum=2*d*a[i]+a[i]-query(i-d,i+d);
        if(sum>0)
        {
            ans=ans+sum;
        }
    }
    cout<<ans<<'\n';
}

signed main()
{
    int t; cin>>t;
    while(t--)
    {
        solve();

    }
}









