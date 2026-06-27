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

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;
void dfs(ll curr,vector<vector<ll>>& g,vector<ll>& s,vector<ll>& nums,ll p=-1)
{
    ll sum=0;
    for(ll i=0; i< g[curr].size(); i++)
    {
        sum+=nums[g[curr][i]];
        if(g[curr][i]==p) continue;
        dfs(g[curr][i],g,s,nums,curr);
    }
    s[curr]=sum;
}
void solve()
{
    ll n;
    cin>>n;
    vector<ll> nums(n+1);
    ll sum=0;
    for(ll i=1; i<= n; i++)
    {
        cin>>nums[i];
        sum+=nums[i];
    }
    vector<ll> s(n+1);
    vector<vector<ll>> g(n+1);
    vector<int> deg(n + 1, 0);
    for(ll i=0 ; i< n-1; i++)
    {
        ll a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        s[a] += nums[b];
        s[b] += nums[a];
        deg[a]++;
        deg[b]++;
    }



    set<vector<ll>> q;

    for(int i = 1; i <= n; i++)
    {
        if((s[i] + nums[i]) % 2 != 0)
        {
            q.insert({nums[i] % 2, deg[i], i});
        }
    }

    vector<ll> ans;
    vector<bool> con(n+1,true);

    while(!q.empty())
    {
        vector<ll> curr = *q.begin();
        ll p=curr[0];
        ll d=curr[1];
        ll u=curr[2];
        q.erase(q.begin());

        con[u] = false;
        ans.push_back(u);

        for(int i=0; i< g[u].size(); i++)
        {
            if(!con[g[u][i]]) continue;
            if((s[g[u][i]] + nums[g[u][i]]) % 2 != 0) {
                q.erase({nums[g[u][i]] % 2, deg[g[u][i]], g[u][i]});
            }

            s[g[u][i]] -= nums[u];
            deg[g[u][i]]--;

            if((s[g[u][i]] + nums[g[u][i]]) % 2 != 0) {
                q.insert({nums[g[u][i]] % 2, deg[g[u][i]], g[u][i]});
            }
        }
    }
    if(ans.size()==n)
    {
        cout<<"YES"<<el;
        for(ll i=0; i< n; i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<el;
    }
    else cout<<"NO"<<el;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}









