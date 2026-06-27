#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,q; cin>>n>>m>>q;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    for(ll i=1; i<= n;i++)
    {
        for(ll j=1; j<=m ;j++)
        {
            ll x; cin>>x;
            dp[i][j]=x+dp[i][j-1];
        }
    }
    for(ll i=1; i<= n;i++)
    {
        for(ll j=1; j<=m ;j++)
        {

            dp[i][j]=dp[i][j]+dp[i-1][j];
        }
    }

    for(ll i=0; i< q;i++)
    {
        ll a,b,c,d; cin>>a>>b>>c>>d;
        ll ans=dp[c][d]-dp[c][b-1]-(dp[a-1][d]-dp[a-1][b-1]);
        cout<<ans<<'\n';
    }

}
