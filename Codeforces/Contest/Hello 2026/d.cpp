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
int depth[N];

void dfs(int curr,vector<vector<int>>& g,int& ans,int d=0,int p=-1)
{
    depth[d]++;
    ans=max(ans,depth[d]);
    if(curr==1)
    {
        ans=max(ans,(int)g[curr].size()+1);
    }
    else{
        ans=max(ans,(int)g[curr].size());
    }
    for(int i=0; i< g[curr].size(); i++)
    {
        if(g[curr][i]!=p)
        {
            dfs(g[curr][i],g,ans,d+1,curr);
        }
    }
}
void sol()
{
    memset(depth,0,sizeof(depth));
    int n; cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=0; i< n-1; i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;
    dfs(1,g,ans);
    cout<<ans<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        sol();
    }
}





