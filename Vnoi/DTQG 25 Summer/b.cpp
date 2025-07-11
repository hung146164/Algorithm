#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m; cin>>n>>m;
    map<ll,ll> dp;
    for(int i=0; i< n; i++ )
    {
        ll x; cin>>x;
        dp[x]++;
    }
    long long ans=0;
    for(int i=0; i< m ;i++)
    {
        ll x; cin>>x;
        ans+=dp[x];
    }
    cout<<ans<<endl;
}
