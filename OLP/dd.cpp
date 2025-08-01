#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
const ll mod=1e9+7;
ll gt[N];
ll ndgt[N];
ll calnd(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p%2==1)
        {
            res=(1LL* res*a)%mod;
        }
        a=(1LL*a*a)%mod;
        p/=2;
    }
    return res;
}
void process() {
    gt[0] = 1;
    for (ll i = 1; i < N; i++) {
        gt[i] = 1LL * gt[i-1] * i % mod;
    }
    for (ll i = 0; i < N; i++) {
        ndgt[i] = calnd(gt[i], mod-2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,m,k;cin>>n>>m>>k;




    process();

    if(k==0)
    {
         cout << gt[n+m-2] * ndgt[n-1] % mod * ndgt[m-1] % mod << '\n';
        return 0;
    }

    vector<vector<ll>> dp(n+1,vector<ll>(m+1,0));
    vector<vector<bool>> valid(n+1,vector<bool>(m+1,true));
    for(ll i=0; i< k; i++)
    {
        ll x, y; cin>>x>>y;
        valid[x][y]=false;
    }
    dp[0][1]=1;
     for(ll i=1; i<=n; i++)
            {
            for(ll j=1; j<=m; j++)
            {
                if(valid[i][j])
                {
                    dp[i][j]=(1LL*dp[i-1][j]+dp[i][j-1])%mod;
                }
            }
        }
        cout<<dp[n][m]<<'\n';


}
