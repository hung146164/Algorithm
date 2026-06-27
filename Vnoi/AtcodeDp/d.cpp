/*
    Author: HungForree
    Link:
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
void sol()
{
    ll n; cin>>n;
    ll w; cin>>w;
    vector<vector<ll>> nums(n,vector<ll>(2));
    for(ll i=0; i< n; i++)
    {
        cin>>nums[i][0]>>nums[i][1];
    }
    vector<vector<ll>> dp(n,vector<ll>(w+1,0));
    ll ans=0;
    for(ll i=0; i<n ;i++)
    {
        for(ll j=0; j<= w; j++)
        {
            if(i==0)
            {
                if(j>=nums[i][0]) dp[i][j]=nums[i][1];
                ans=max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                if(j>=nums[i][0]) dp[i][j]=max(dp[i-1][j-nums[i][0]]+nums[i][1],dp[i][j]);
                ans=max(ans,dp[i][j]);
            }

            //cout<<dp[i][j]<<' ';
        }
        //cout<<'\n';

    }
    cout<<ans<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        sol();
    }
}





