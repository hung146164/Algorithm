/*
    Author: HungForree
    Link: https://codeforces.com/problemset/problem/1328/E
*/

#include<bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>

typedef long long ll;
const ll N=2e5+5;
const ll mod=1e9+7;
const ll modr=1e9+9;

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;
using i128 = __int128;
constexpr i64 inf = 1E18;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n,q;
int depth[N];
int parent[18][N];
vector<int> g[N];
void dfs(int curr,int d=1,int p=0)
{
    depth[curr]=d;
    parent[0][curr]=p;
    for(auto& v: g[curr])
    {
        if(v==p) continue;
        dfs(v,d+1,curr);
    }
}
int lca(int a, int b)
{
    if(depth[a]<depth[b])
    {
        swap(a,b);
    }
    for(int i=17; i>=0; i--)
    {
        if(depth[parent[i][a]]>=depth[b])
        {
            a=parent[i][a];
        }
    }
    if(a==b) return a;
    for(int i=17; i>=0; i--)
    {
        if(parent[i][a]!=parent[i][b])
        {
            a=parent[i][a];
            b=parent[i][b];
        }
    }
    return parent[0][a];
}
void solve()
{
    cin>>n>>q;
    for(int i=1;i<n; i++)
    {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for(int i=1;i<18; i++)
    {
        for(int j=1;j<=n; j++)
        {
            parent[i][j]=parent[i-1][parent[i-1][j]];
        }
    }
    //cerr<<"OK"<<el;
    while(q--)
    {
        int k; cin>>k;
        vector<int> v(k);
        int d_max=0;
        int u=0;
        for(int i=0; i< k; i++)
        {
            cin>>v[i];
            if(d_max<depth[v[i]])
            {
                d_max=depth[v[i]];
                u=v[i];
            }
        }
        bool ok=true;
        for(int i=0; i< k; i++)
        {
            if(depth[v[i]]-depth[lca(v[i],u)]>1)
            {
                ok=false;
                break;
            }
        }
        if(ok) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t; t=1;
    while(t--)
    {
        solve();
    }
}









