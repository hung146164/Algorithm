#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> dp;
ll mod=1e9;
ll cal(ll x)
{
    return ((1LL*x*x %mod) +(1LL*2*x %mod )+3) %mod;
}
int main()
{
    ll n,x; cin>>n>>x;
    dp[x]=0;
    ll ck=-1;
    vector<ll> ans;
    ans.push_back(x);
    bool have=false;
    for(ll i=1;i<=n; i++)
    {
        x=cal(x);
        //cout<<x<<'\n';
        if(dp.find(x)!=dp.end())
        {
            ck=i;
            have=true;
            break;
        }
        ans.push_back(x);
        dp[x]=i;
    }
    if(!have)
    {
        cout<<x<<'\n';
    }
    else
    {
        ll start=dp[x];
        ll lap=ck-dp[x];
        n=n-start;
        cout<<ans[start+n%lap]<<'\n';
    }

}
