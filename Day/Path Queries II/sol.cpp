/*
    Author: HungForree
    Link: https://cses.fi/problemset/task/2134/
*/
#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
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

int heavy[N],in[N],head[N],depth[N],parent[N];
vector<int> g[N];
int n,q ;
int dfs1(int curr ,int p=0,int d=1)
{
    depth[curr]=d;
    parent[curr]=p;
    int child_cnt=1;
    int child_max=0;
    int child_max_cnt=0;
    for(auto& v: g[curr])
    {
        if(v==p) continue;
        int cnt=dfs1(v,curr,d+1);
        child_cnt+=cnt;
        if(child_max_cnt<cnt)
        {
            child_max_cnt=cnt;
            child_max=v;
        }
    }
    heavy[curr]=child_max;
    if(child_max!=0)
    {
        int child_max_idx=0;
        for(int i=0; i<g[curr].size(); i++)
        {
           if(g[curr][i]==child_max) child_max_idx=i;
        }
        swap(g[curr][0],g[curr][child_max_idx]);
    }
    return child_cnt;
}
int id=1;
void dfs2(int curr ,int base)
{
    in[curr]=id;
    id++;
    head[curr]=base;
    for(int i=0; i< g[curr].size(); i++)
    {
        int v=g[curr][i];
        if(v==parent[curr]) continue;

        if(i==0)
        {
            dfs2(v,base);
        }
        else dfs2(v,v);
    }
}



int tree[N*4];
int nums[N];
int new_val[N];

void build(int curr ,int l, int r)
{
    if(l==r)
    {
        tree[curr]=new_val[l];
        return;
    }
    int m=(l+r)>>1;
    build(curr<<1,l,m);
    build(curr<<1|1,m+1,r);
    tree[curr]=max(tree[curr<<1],tree[curr<<1|1]);
}
void update(int curr, int l, int r, int x, int val)
{
    if(l==r)
    {
        tree[curr]=val;
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) update(curr<<1,l,m,x,val);
    else update(curr<<1|1,m+1,r,x,val);
    tree[curr]=max(tree[curr<<1],tree[curr<<1|1]);
}
int query(int curr, int l, int r, int x,int y)
{
    if(r<x || l>y) return 0;
    if(x<=l && r<=y) return tree[curr];
    int m=(l+r)>>1;
    return max(query(curr<<1,l,m,x,y),query(curr<<1|1,m+1,r,x,y));
}
int pathquery(int a, int b)
{
    int ans=0;
    while(head[a]!=head[b])
    {
        if(depth[head[a]]<depth[head[b]])
        {
            swap(a,b);
        }
        ans=max(query(1,1,n,in[head[a]],in[a]),ans);
        a=parent[head[a]];
    }
    if(depth[a]<depth[b]) swap(a,b);
    ans=max(ans,query(1,1,n,in[b],in[a]));
    return ans;
}
void solve()
{
     cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>nums[i];
    }
    for(int i=0; i< n-1; i++)
    {
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1);
    dfs2(1,1);
    for(int i=1; i<=n; i++)
    {
        new_val[in[i]]=nums[i];
    }
//    for(int i=1;i<=n; i++) cout<<in[i]<<' ';
//    cout<<el;
//    for(int i=1;i<=n; i++) cout<<new_val[i]<<' ';
//    cout<<el;
//    for(int i=1;i<=n; i++) cout<<head[i]<<' ';
//    cout<<el;


    build(1,1,n);
    while(q--)
    {
        int t; cin>>t;
        int a, b; cin>>a>>b;
        if(t==1)
        {
            update(1,1,n,in[a],b);
        }
        else
        {
            cout<<pathquery(a,b)<<' ';
        }
    }
    cout<<el;
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









