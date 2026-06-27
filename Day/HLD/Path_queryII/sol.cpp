/*
    Author: HungForree
    Link: https://cses.fi/problemset/task/2134
*/
#pragma GCC optimize("O3,unroll-loops")
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
vector<int> g[N];
int val[N];
//dfs1
int parent[N], depth[N], heavy[N],sz[N];


// dfs2
int head[N],pos[N],cur_pos=1;

//Segmentree
int st[4*N];

// hld

int dfs1(int curr ,int p=0,int d=1)
{
    parent[curr]=p;
    depth[curr]=d;
    sz[curr]=1;
    int max_sz=-1;
    int heavy_child=-1;
    for(int i=0; i< g[curr].size(); i++)
    {
        int v=g[curr][i];
        if(v==p) continue;

        sz[curr]+=dfs1(v,curr,d+1);
        if(sz[v]>max_sz)
        {
            max_sz=sz[v];
            heavy_child=i;
        }
    }
    if(heavy_child!=-1)
    {
        heavy[curr]=g[curr][heavy_child];
        swap(g[curr][0],g[curr][heavy_child]);
    }
    return sz[curr];
}
void dfs2(int curr ,int head_node)
{
    head[curr]=head_node;
    pos[curr]=cur_pos;
    cur_pos++;

    for(int i=0; i< g[curr].size(); i++)
    {
        int v=g[curr][i];
        if(v==parent[curr]) continue;

        if(v==g[curr][0])
        {
            dfs2(v,head_node);
        }
        else
        {
            dfs2(v,v);
        }
    }
}

void update(int id,int l, int r, int x,int val)
{
    //cout<<l<<' '<<r<<endl;
    if(l==r)
    {
        st[id]=val;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
    {
        update(id<<1,l,m,x,val);
    }
    else update(id<<1 | 1,m+1,r,x,val);
    st[id]=max(st[id<<1],st[id<<1 | 1]);
}
int get(int id, int l, int r, int x, int y)
{
    if(r<x || l> y) return 0;
    if(x<=l && r<=y) return st[id];
    int m=(l+r)>>1;
    return max(get(id<<1,l,m,x,y),get(id<<1|1,m+1,r,x,y));
}
// hld
int querypath(int u,int v)
{
    int ans=0;
    while(head[u]!=head[v])
    {
        if(depth[head[u]]<depth[head[v]])
        {
            swap(u,v);
        }
        ans=max(ans,get(1,1,n,pos[head[u]],pos[u]));

        u=parent[head[u]];
    }
    if(depth[u]>depth[v])
    {
        swap(u,v);
    }
    ans=max(ans,get(1,1,n,pos[u],pos[v]));
    return ans;
}
int new_val[N];
void build(int id, int l, int r)
{
    if(l==r)
    {
        st[id]=new_val[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}
void solve()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>val[i];
    }
    for(int i=0; i<n-1; i++)
    {
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1);
    //cout<<"OK dfs1"<<endl;
    dfs2(1,1);
    //cout<<"OK dfs2"<<endl;
    for(int i=1; i<=n;i++)
    {
        new_val[pos[i]]=val[i];
    }
    build(1,1,n);
    //cout<<"update ok"<<endl;
    while(q--)
    {
        int type; cin>>type;
        if(type==1)
        {
            int s,x; cin>>s>>x;
            update(1,1,n,pos[s],x);
        }
        else
        {
            int a,b; cin>>a>>b;
            cout<<querypath(a,b)<<' ';
        }
    }
    cout<<el;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t=1;
    while(t--)
    {
        solve();
    }
}

