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
const ll mod=1e9+7;
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

ll find(ll u, vector<ll>& parent)
{
    if(parent[u]==u) return u;
    return parent[u]=find(parent[u],parent);
}
void join(ll a, ll b, vector<ll>& parent, vector<ll>& len, ll& ans)
{
    ll pa=find(a,parent);
    ll pb=find(b,parent);

    if(pa==pb) return;

    ans-=len[pa]*(len[pa]+1)/2;
    ans-=len[pb]*(len[pb]+1)/2;

    parent[pb]=pa;
    len[pa]+=len[pb];

    ans+=len[pa]*(len[pa]+1)/2;
}
void solve()
{
    ll n; cin>>n;
    vector<ll> nums(n);

    for(ll i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    vector<ll> diff(n-1);
    for(ll i=0; i<n-1; i++)
    {
        diff[i]=abs(nums[i+1]-nums[i]);
    }
    vector<ll> parent(n);
    vector<ll> len(n);
    for(ll i=0; i<n; i++)
    {
        parent[i]=i;
        len[i]=1;
    }
    vector<pair<ll,ll>> dp;
    for(ll i=0; i<diff.size(); i++)
    {
        dp.push_back({diff[i],i});
    }
    sort(dp.begin(),dp.end(),greater<pair<ll,ll>>());
    vector<bool> active(n);
    vector<ll> res(n);
    ll ans=0;
    ll curr=0;
    for(ll i=n-1; i>=1; i--)
    {
        while(curr<dp.size() && i<=dp[curr].first)
        {
            ll val=dp[curr].second;
            active[val]=true;
            ans++;

            if(val>0 && active[val-1])
            {
                join(val-1,val,parent,len,ans);
            }

            if(val<dp.size()-1 && active[val+1])
            {
                join(val,val+1,parent,len,ans);
            }

            curr++;
        }
        res[i]=ans;
    }
    for(ll i=1; i<n; i++) cout<<res[i]<<' ';
    cout<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }
}
