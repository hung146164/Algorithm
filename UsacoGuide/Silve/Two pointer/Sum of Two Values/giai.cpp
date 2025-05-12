#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll,ll> sol()
{
    ll n, v; cin>>n>>v;
    map<ll,ll> dp;
    ll ans1=-1, ans2=-1;
    for(ll i=0; i< n;i ++)
    {
        ll x; cin>>x;

        if(dp.find(v-x)!=dp.end())
        {
            return {dp[v-x],i};
        }

        dp[x]=i;
    }
    return {-1,-1};
}
int main()
{
    pair<ll,ll> ans=sol();
    if(ans.first==ans.second && ans.first==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else cout<<ans.first+1<<" "<<ans.second+1<<endl;

}
