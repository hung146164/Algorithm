#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,q;cin>>n>>m>>q;
    vector<vector<ll>> dp(n+2,vector<ll>(m+2,0));
    while(q--)
    {
        ll a, b, c, d;cin>>a>>b>>c>>d;
        dp[a][b]+=1;
        dp[a][d+1]+=-1;
        dp[c+1][b]+=-1;
        dp[c+1][d+1]+=1;
    }
    for(ll i=1; i<=n+1; i++)
    {
        for(ll j=1; j<=m+1; j++)
        {
            dp[i][j]+=dp[i][j-1];
        }
    }
    for(ll i=1; i<= n+1; i++)
    {
        for(ll j=1; j<=m+1; j++)
        {
            dp[i][j]+=dp[i-1][j];
        }
    }

    for(ll i=1; i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }

}
