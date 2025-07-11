#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sang(vector<ll>& dp,ll r)
{
    for(int i=1; i<=r ;i++)
    {
        for(int j=i;j<=r;j+=i)
        {
            dp[j]+=i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SPECIAL.INP","r",stdin);
    freopen("SPECIAL.OUT","w",stdout);
    ll l,r; cin>>l>>r;
    vector<ll> dp(r+1);
    sang(dp,r);
    int ans=0;
    for(ll i=l; i<=r ; i++)
    {
        if(dp[i]>i*2)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
