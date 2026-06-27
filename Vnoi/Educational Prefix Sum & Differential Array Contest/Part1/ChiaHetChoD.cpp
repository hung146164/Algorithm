#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<ll,ll> dp;
    ll n; cin>>n;
    ll k;cin>>k;
    ll curr=0;
    ll ans=0;
    dp[0]=1;
    for(ll i=0; i< n;i++)
    {
        ll x; cin>>x;
        curr+=x;
        curr=(curr%k+k)%k;
        ans+=dp[curr];
        //cout<<dp[curr]<<' ';
        dp[curr]++;
    }
    cout<<ans<<'\n';
}
