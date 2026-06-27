/*
    Author: HungForree
    Link: https://oj.vnoi.info/problem/atcoder_dp_g
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;
const ll inf=1e18;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll base=rng() % 500 +300;
ll powll(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
int sol(int curr ,vector<vector<int>>& g, vector<int>& dp)
{
    if(dp[curr]!=-1) return dp[curr];
    int ans=1;
    int val=0;
    for(int i=0; i< g[curr].size(); i++)
    {
        val=max(val,sol(g[curr][i],g,dp));
    }

    return dp[curr]=ans+val;
}
void solve()
{
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> g(n);
    for(int i=0; i< m; i++)
    {
        int a, b; cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
    }

    vector<int> dp(n,-1);
    for(int i=0; i< n; i++)
    {
        sol(i,g,dp);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        //cout<<dp[i]<<' ';
        ans=max(ans,dp[i]);
    }
    //cout<<'\n';
    cout<<ans-1<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}





