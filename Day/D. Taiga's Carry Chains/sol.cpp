
#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=5005;
const ll mod=1e9+7;
const ll modr=1e9+9;


ll nums[N],cnt[N][N];
void solve()
{
    ll n, q; cin>>n>>q;
    for(ll i=1; i<=n; i++)
    {
        cin>>nums[i];
    }
    for(ll i=1; i<=n; i++)
    {
        unordered_map<ll,ll> mp;
        ll ans=0;
        for(ll j=i+1;j<=n; j++)
        {
            ll val=nums[i]+nums[j];
            ans+=mp[-val];
            mp[nums[j]]++;
            cnt[i][j]=ans;
        }
    }
    for(ll i=n; i>=1; i--)
    {
        for(ll j=1;j<=n; j++)
        {
            cnt[i][j]+=cnt[i+1][j];
        }
    }
    while(q--)
    {
        ll a, b; cin>>a>>b;
        cout<<cnt[a][b]<<el;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; t=1;
    while(t--)
    {
        solve();
    }
}










