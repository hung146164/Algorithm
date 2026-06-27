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
const ll mod=998244353;
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

vector<vector<ll>> uoc(3001);
void sang()
{
    for(ll i=1; i< 3001; i++)
    {
        for(ll j=1;j*j<=i; j++)
        {
            if(i%j==0)
            {
                uoc[i].push_back(j);
                if(i/j!=j)
                {
                    uoc[i].push_back(i/j);
                }
            }
        }
    }
}
ll dfs(ll curr ,vector<ll>& nums,ll& m,ll pre,vector<vector<ll>>& dp)
{
    if(curr==nums.size()) return 1;
    if(dp[curr][pre]!=-1) return dp[curr][pre];
    ll ans=0;
    if(nums[curr]!=0)
    {
        if(nums[curr]<=pre) return 0;
        if( pre%(nums[curr]-pre) !=0) return 0;
        ans=(ans+dfs(curr+1,nums,m,nums[curr],dp))%mod;
    }
    else{
        for(auto val : uoc[pre])
        {
            if(pre+val<=m) ans=(ans+dfs(curr+1,nums,m,pre+val,dp))%mod;
        }
    }
    return dp[curr][pre]=ans;
}

void sol()
{
    //memset(dp,-1,sizeof(dp));

    ll n,m; cin>>n>>m;
    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));
    vector<ll> nums;
    for(ll i=0; i< n; i++)
    {
        ll x; cin>>x;
        nums.push_back(x);
    }

    if(nums[0]==0 || nums[0]==1)
    {
        cout<<dfs(1,nums,m,1,dp)<<el;
    }
    else cout<<0<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    sang();
    ll t; cin>>t;
    while(t--)
    {
        sol();
    }
}




