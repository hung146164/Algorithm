#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=1e7+1;
int dp[N][2];
typedef long long ll;
int sol(ll& n,ll curr=1, bool ok=false)
{
    if(curr>n) return 1;
    if(dp[curr][ok]!=-1) return dp[curr][ok];
    ll ans=0;
    //dat 2x2 && 1x2
    if(curr<=n-1)
    {
         if(!ok) ans=(ans+sol(n,curr+2,true))%mod;
        ans=(ans+sol(n,curr+2,false))%mod;
    }
    //dat 2x1
    ans=(ans+sol(n,curr+1,false))%mod;
    return dp[curr][ok]=ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    ll n; cin>>n;

    cout<<sol(n)<<'\n';
}
