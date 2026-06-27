#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=55;
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
ll base=100019;
ll pow61[N],in61[N];
ll pow62[N],in62[N];
pair<ll,ll> dp[1005][1005];
void process()
{
    pow61[0]= in61[0]=1;
    ll i61=powll(base,mod-2);
    ll i62=powll(base,modr-2);
    for(ll i=1; i< N; i++)
    {
        pow61[i]=pow61[i-1]*base;
        if(pow61[i]>=mod) pow61[i]-=mod;

        in61[i]=in61[i-1]*i61%mod;
        if(in61[i]>=mod) in61[i]-=mod;

        pow62[i]=pow62[i-1]*base%modr;
        if(pow62[i]>=mod) pow62[i]-=modr;

        in62[i]=in62[i-1]*i62%modr;
        if(in62[i]>=mod) in62[i]-=mod;
    }
}
inline void add1(ll &a, ll b) {
    a += b;
    if (a >= MOD1) a -= MOD1;
    else if (a < 0) a += MOD1;
}

inline void add2(ll &a, ll b) {
    a += b;
    if (a >= MOD2) a -= MOD2;
    else if (a < 0) a += MOD2;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    process();
    ll n, m , p; cin>>n>>m>>p;
    for(ll i=0; i< p; i++)
    {
        ll a, b, c, d, x;
        cin>>a>>b>>c>>d>>x;
        dp[a][b].first=add1(dp[a][b].first,pow61[x]);
        if(d+1<=n) dp[a][d+1].first=add1(dp[a][d+1].first,-1LL*pow61[x]);
        if(c+1<=n) dp[c+1][b].first=add1(dp[c+1][b].first,-1LL*pow61[x]);
        if(c+1<=n && d+1<=n) dp[c+1][d+1].first=add1(dp[c+1][d+1].first,pow61[x]);

        dp[a][b].second=add2(dp[a][b].second,pow62[x]);
        if(d+1<=n) dp[a][d+1].second=add2(dp[a][d+1].second,-1LL*pow62[x]);
        if(c+1<=n) dp[c+1][b].second=add2(dp[c+1][b].second,-1LL*pow62[x]);
        if(c+1<=n && d+1<=n) dp[c+1][d+1].second=add2(dp[c+1][d+1].second,pow62[x]);

    }
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            dp[i][j].first=(dp[i][j].first+dp[i][j-1].first)%mod;

            dp[i][j].second=(dp[i][j].second+dp[i][j-1].second)%modr;
        }
    }
    vector<pair<ll,ll>> ar;
    ar.reserve(n * n);
    for(ll i =1; i <=n; i ++)
    {
        for(ll j=1; j<=n; j++)
        {
            dp[i][j].first=(dp[i][j].first+dp[i-1][j].first)%mod;
            dp[i][j].second=(dp[i][j].second+dp[i-1][j].second)%modr;
            //cout<<dp[i][j]<<' ';
            ar.push_back(dp[i][j]);
        }
        //cout<<el;
    }
    sort(ar.begin(),ar.end());
    ll q; cin>>q;
    while(q--)
    {
        ll a, b; cin>>a>>b;
        pair<ll,ll> target=dp[a][b];
        cout<<upper_bound(ar.begin(),ar.end(),target)-
        (lower_bound(ar.begin(),ar.end(),target))<<el;
    }

}

