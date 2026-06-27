#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+1;

ll maxll(ll a,ll b)
{
    if(a>b) return a;
    return b;
}
ll minll(ll a,ll b)
{
    if(a>b) return b;
    return a;
}
ll gdc(ll a, ll b)
{
    if(b==0) return a;
    return gdc(b,a%b);
}

namespace sub1
{
    bool CheckSub1()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub2
{
    bool CheckSub2()
    {
        return true;
    }
    void sol()
    {

    }
}
namespace sub3
{
    bool CheckSub3()
    {
        return true;
    }
    void sol()
    {

    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m,k; cin>>n>>m>>k;

    vector<vector<pair<ll,ll>>> parent(n);
    for(ll i=0; i< m; i++)
    {
        ll a, b,c; cin>>a>>b>>c;
        a--;
        b--;
        parent[b].push_back({a,c});
    }
    vector<vector<ll>> dp(k+1,vector<ll>(n,INT_MAX));
    dp[0][0]=0;
    for(ll i=1; i<=k; i++)
    {
        for(ll j=0; j<n; j++)
        {
            ll minn=INT_MAX;
            for(auto& p: parent[j])
            {
                minn=min(dp[i-1][p.first]+p.second,minn);
            }
            dp[i][j]=minn;
        }
    }
    cout<<(dp[k][n-1]==INT_MAX?-1:dp[k][n-1])<<'\n';

}


