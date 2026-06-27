#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;
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
ll pow2[51];
void process()
{
    pow2[0]=1;
    for(int i=1; i< 51; i++)
    {
        pow2[i]=pow2[i-1]*2%mod;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n, m,p; cin>>n>>m>>p;
    process();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));

    for(ll i=0; i< p; i++)
    {
        ll a, b,c,d,x; cin>>a>>b>>c>>d>>x;
        ll val=pow2[x-1];
        dp[a][b]=((dp[a][b]+val)%mod+mod)%mod;
        if(d+1<=n) dp[a][d+1]=((dp[a][d+1]-val)%mod+mod)%mod;
        if(c+1<=n) dp[c+1][b]=((dp[c+1][b]-val)%mod+mod)%mod;
        if(c+1<=n && d+1<=n) dp[c+1][d+1]=(dp[c+1][d+1]+val)%mod;
    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
        }
    }
    for(ll j=1; j<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
    }
    map<ll,ll> mp;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            mp[dp[i][j]]++;
        }
    }
//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=n; j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<el;
//    }
    ll q; cin>>q;
    while(q--)
    {
        ll a, b; cin>>a>>b;
        cout<<mp[dp[a][b]]<<el;
    }
}
