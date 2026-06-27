#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxll(ll a,ll b)
{
    return (a>b?a:b);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); // Them cai nay cho nhanh
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> candidate;
    vector<vector<ll>> dp(2*n+1,vector<ll>(2*n+1));
    for(ll i=0; i< n; i++)
    {
        for(ll j=0; j< n; j++)
        {
            candidate.push_back({i+j,i-j+n});
            cin>>dp[i+j][i-j+n];
        }
    }
    //prefix ngang

    for(ll i=0; i<=2*n;i++)
    {
        for(ll j=0; j<=2*n;j++)
        {
            ll pre=j-1>=0?dp[i][j-1]:0;
            dp[i][j]+=pre;
        }
    }
    //prefix doc
    for(ll i=0; i<=2*n;i++)
    {
        for(ll j=0; j<=2*n;j++)
        {
            ll pre=i-1>=0?dp[i-1][j]:0;
            dp[i][j]+=pre;
        }
    }
    ll ans=0;
    for(auto&[i,j]: candidate)
    {
        bool one=(j+k<=2*n);
        bool two=(j-k-1>=0);
        bool three=(i-k-1>=0);
        bool four=(i+k<=2*n);
        ans=maxll(ans,( (one && four)?dp[i+k][j+k]:0)-((two&&one)?dp[i+k][j-k-1]:0) - ( ((one && three)? dp[i-k-1][j+k]:0) - ((two && three)?dp[i-k-1][j-k-1]:0)));
    }

    cout<<ans<<'\n';

}
