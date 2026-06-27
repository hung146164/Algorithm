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

ll dfs(ll n,ll k,map<pair<ll,ll>,ll>& dp,ll d=0)
{
    if(n<k) return INT_MAX;
    if(n==k)
    {
        return d;
    }
    if(dp.find({n,k})!=dp.end()) return dp[{n,k}];
    ll ans=min(dfs((n+1)/2,k,dp,d+1),dfs(n/2,k,dp,d+1));
    dp[{n,k}]=ans;
    return ans;

}
void solve()
{

    ll n,k; cin>>n>>k;
    map<pair<ll,ll>,ll> dp;
    ll ans=dfs(n,k,dp);
    cout<<(ans==INT_MAX?-1:ans)<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}







