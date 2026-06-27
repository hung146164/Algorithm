#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll N=1e6+5;
ll gt[N],ingt[N];

ll minll(ll a,ll b)
{
    return a>b?b:a;
}
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
void process()
{
    gt[0]=ingt[0]=1;
    for(ll i=1; i<N ;i++ )
    {
        gt[i]=gt[i-1]*i %mod;
        ingt[i]=ingt[i-1]*powll(i,mod-2)%mod;
    }
}
ll C(ll n,ll k)
{
    return (gt[n]*ingt[k] %mod ) * ingt[n-k] %mod;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k; cin>>n>>m>>k;
    process();
    vector<vector<ll>> dp(1001,vector<ll>(1001,0));
    vector<vector<bool>> valid(1001,vector<bool>(1001,true));
    for(ll i=0; i< k; i++)
    {
        ll a,b; cin>>a>>b;
        valid[a][b]=false;
    }
    dp[0][1]=1;
    for(ll i=1; i<=1000; i++)
    {
        for(ll j=1; j<=1000;j++)
        {
            if(!valid[i][j]) continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
        }
    }
    if(n<=1000 && m<=1000)
    {
        cout<<dp[n][m]<<'\n';
    }
    else
    {
        //cout<<"Done1"<<endl;
        ll ans=0;
        if(m>1000)
        {
            for(ll i=1;i<=minll(n,1000ll); i++)
            {
                ll currx=i;
                ll curry=1001;
                ans=(ans+(dp[i][1000]* C(n-currx+m-curry,n-currx)%mod))%mod;
            }
        }
        //cout<<"Done"<<endl;
        if(n>1000)
        {
            for(ll i=1;i<=minll(m,1000ll); i++)
            {
                ll currx=1001;
                ll curry=i;
                ans=(ans+ (dp[1000][i]* C(n-currx+m-curry,n-currx)%mod))%mod;
            }
        }
        cout<<ans<<'\n';
    }



}


