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
int parent[N],in[N],out[N];
int depth[N];
vector<int> g[N];
int id=1;
void dfs(int curr,int d=1,int p=0)
{
    depth[curr]=d;
    in[curr]=id;
    id++;

    parent[curr]=p;
    for(auto& v: g[curr])
    {
        if(v==p) continue;
        dfs(v,d+1,curr);
    }
    out[curr]=id;
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
    parent[1]=1;
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
            v[i]=parent[v[i]];
        }
        bool ok=true;
        for(int i=0; i< k; i++)
        {
            if((in[v[i]] <= in[u] && out[v[i]]>=out[u]))
            {
                continue;
            }
            ok=false;
            break;
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









