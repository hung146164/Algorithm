#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k; cin>>n>>k;
    vector<ll> prefix(1,0);
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;
        prefix.push_back(prefix[i]+x);
    }
    unordered_map<ll,ll> dp;
    ll ans=0;
    for(ll i=0; i< prefix.size(); i++)
    {
        ll candidate=(prefix[i]-k*i);
        ans+=dp[candidate];
        dp[candidate]++;
    }
    cout<<ans<<'\n';
}
